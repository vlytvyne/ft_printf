/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:44:20 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:44:23 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*get_decimal_str(t_form form, va_list args, int base)
{
	if (form.ll)
		return (itoa_base(va_arg(args, long long int), base));
	else if (form.l)
		return (itoa_base(va_arg(args, long int), base));
	else if (form.hh)
		return (itoa_base((char)va_arg(args, int), base));
	else if (form.h)
		return (itoa_base((short int)va_arg(args, int), base));
	else
		return (itoa_base(va_arg(args, int), base));
}

static char	*get_unsigned_str(t_form form, va_list args, int base)
{
	if (form.ll)
		return (uitoa_base(va_arg(args, unsigned long long int), base));
	else if (form.l)
		return (uitoa_base(va_arg(args, unsigned long int), base));
	else if (form.hh)
		return (uitoa_base((unsigned char)va_arg(args, unsigned int), base));
	else if (form.h)
		return (uitoa_base((unsigned short int)va_arg(args, unsigned int),
			base));
	else
		return (uitoa_base(va_arg(args, unsigned int), base));
}

static char	*get_float_str(t_form form, va_list args)
{
	if (form.upper_l)
		return (ftoa(va_arg(args, long double),
			form.precision_set ? form.precision : 6));
	else
		return (ftoa(va_arg(args, double),
			form.precision_set ? form.precision : 6));
}

char		*get_num_str(t_form form, va_list args)
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
		result = get_decimal_str(form, args, base);
	else if (ft_strchr("uoxX", form.type))
		result = get_unsigned_str(form, args, base);
	else if (form.type == 'f')
		result = get_float_str(form, args);
	if (*result == '0' && form.type != 'f'
		&& form.precision_set && form.precision == 0)
		*result = '\0';
	if (form.type == 'x')
	{
		i = -1;
		while (result[++i])
			result[i] = ft_tolower(result[i]);
	}
	return (result);
}
