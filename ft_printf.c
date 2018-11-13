/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:40:50 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 14:41:09 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "header.h"

t_form	parse(char **format)
{
	t_form	form;
	int		dot_found;

	after_dot = 0;
	form = (t_form){0};
	while (**format)
	{//!!!pointer stays on conversion char
		if (ft_strchr(CONVERSIONS, **format))
		{
			form.type = **format;
			return(form);
		}
		if (ft_strchr(FLAGS, **format))
		{
			if (**format == '#')
				form.hash = 1;
			else if (**format == '0')
				form.zero = 1;
			else if (**format == '-')
				form.minus = 1;
			else if (**format == '+')
				form.plus = 1;
			else if (**format == ' ')
				form.space = 1;
			else if (**format == 'L')
				form.upper_l = 1;
			else if (**format == 'l')
			{//можно всунуть тернарники
				if (*(*format + 1) == 'l')
					form.ll = 1;
				else
					form.l = 1;
			}
			else if (**format == 'h')
			{
				if (*(*format + 1) == 'h')
					form.hh = 1;
				else
					form.h = 1;
			}
		}
		if (ft_isdigit(**format))
		{
			if (!after_dot)
			{
				form.width = ft_atoi(*format);
				after_dot = 1;
			}
			else
				form.precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		(*format)++;
	}
	return (form);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			format++;
			if (*format == '%')
				ft_putchar('%');
			else
			{

			}
		}
		format++;
	}
	va_end(args);
	return (0);
}
