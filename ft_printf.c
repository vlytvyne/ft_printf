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

#include "libft.h"
#include "header.h"

t_form	parse(const char **format)
{
	t_form	form;

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
			else if (**format == '0' && !form.precision_set)
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
			if (!form.precision_set)
				form.width = ft_atoi(*format);
			else
				form.precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
		if (**format == '.')
			form.precision_set = 1;
		(*format)++;
	}
	return (form);
}

void	width_manager(t_form form, char **src)
{//обрабатывает с минусом
	int		srclen;
	int		cpy_from;
	int		i;
	int		width;
	char	*new_str;

	width = form.width;
	srclen = ft_strlen(*src);
	if (width <= srclen)
		return ;
	new_str = ft_strnew(width);
	if (form.minus)
	{
		ft_strcpy(new_str, *src);
		while (srclen < width)
			new_str[srclen++] = ' ';
	}
	else
	{
		cpy_from = width - srclen;
		ft_strcpy(new_str + cpy_from, *src);
		i = 0;
		while (i < cpy_from)
			new_str[i++] = ' ';
	}
	free(*src);
	*src = new_str;
}

void	precision_manager(t_form form, char **src)
{
	char	*new_str;
	char	*to_free;
	int		size;

	if (form.type == 's')
	{
		if (form.precision_set && form.precision < ft_strlen(*src))
		{
			to_free = *src;		
			*src = ft_strsub(*src, 0, form.precision);
			free(to_free);
		}
	}
	else if (ft_strchr("diouxX", form.type))
	{
		size = form.precision - ft_strlen(*src);
		if (size <= 0)
			return ;
		to_free = ft_strnew(size);
		while (--size >= 0)
			to_free[size] = '0';
		new_str = ft_strjoin(to_free, *src);
		free(*src);
		free(to_free);
		*src = new_str;
	}
}

void	plus_space_manager(t_form form, char **src)
{
	char *new_str;
	char ch;

	if (ft_strchr("dif", form.type) && (form.space || form.plus))
	{
		if (form.plus)
			new_str = ft_strjoin("+", *src);
		else
			new_str = ft_strjoin(" ", *src);
		free(*src);
		*src = new_str;
	}
}

void	hash_manager(t_form form, char **src)
{
	char *new_str;

	new_str = NULL;
	if (form.type == 'o')
		new_str = ft_strjoin("0", *src);
	else if (form.type == 'x' || form.type == 'X')
		new_str = ft_strjoin("0x", *src);
	else if (form.type == 'f' && form.precision_set && form.precision == 0)
		new_str = ft_strjoin(*src, ".");
	if (new_str != NULL)
	{
		free(*src);
		*src = new_str;
	}
}

char	*get_pointer_str(va_list args)
{
	int 	i;
	int		size;
	char	*tmp;
	char	*result;

	i = 0;
	tmp = itoa_base(va_arg(args, long long unsigned int), 16);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	result = ft_strjoin("0x", tmp);
	free(tmp);
	return (result);
}

char	*get_num_str(t_form form, va_list args)
{
	char	*result;
	int		base;
	int		i;

	if (form.type == 'o')
		base = 8;
	else if (form.type == 'x' || form.type == 'X')
		base = 16;
	else
		base = 10;
	if (form.type == 'd' || form.type == 'i')
	{
		if (form.ll)
			result = itoa_base(va_arg(args, long long int), base);
		else if (form.l)
			result = itoa_base(va_arg(args, long int), base);
		else if (form.hh)
			result = itoa_base((char)va_arg(args, int), base);
		else if (form.h)
			result = itoa_base((short int)va_arg(args, int), base);
		else
			result = itoa_base(va_arg(args, int), base);
	}
	else if (form.type == 'u' || form.type == 'o' || form.type == 'x' || form.type == 'X')
	{
		if (form.ll)
			result = uitoa_base(va_arg(args, unsigned long long int), base);
		else if (form.l)
			result = uitoa_base(va_arg(args, unsigned long int), base);
		else if (form.hh)
			result = uitoa_base((unsigned char)va_arg(args, unsigned int), base);
		else if (form.h)
			result = uitoa_base((unsigned short int)va_arg(args, unsigned int), base);
		else
			result = uitoa_base(va_arg(args, unsigned int), base);
	}
	else if (form.type == 'f')
	{
		if (form.upper_l)
			result = ftoa(va_arg(args, long double), form.precision);
		else
			result = ftoa(va_arg(args, double), form.precision);
	}
	if (form.type == 'x')
	{
		i = 0;
		while (result[i])
		{
			result[i] = ft_tolower(result[i]);
			i++;
		}

	}
	return (result);
}

int		dispatcher(t_form form, va_list args)
{
	char	*result;

	if (form.type == 'c')
	{
		result = ft_strnew(1);
		*result = va_arg(args, int);
	}
	else if (form.type == 's')
	{
		result = ft_strdup(va_arg(args, char*));
		if (result == NULL)
			result = ft_strdup("(null)");
	}
	else if (form.type == 'p')
		result = get_pointer_str(args);
	else if (ft_strchr("diouxXf", form.type))
		result = get_num_str(form, args);
	precision_manager(form, &result);
	plus_space_manager(form, &result);
	hash_manager(form, &result);
	width_manager(form, &result);
	ft_putstr(result);
	return (ft_strlen(result));
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_form	form;
	char	*str;
	int		printed;

	printed = 0;
    va_start(args, format);
    while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			printed++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				ft_putchar('%');
				printed++;
			}
			else
			{
				form = parse(&format);
				printed += dispatcher(form, args);
			}
		}
		format++;
	}
	va_end(args);
	return (printed);
}
