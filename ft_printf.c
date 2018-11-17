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

void	set_flag(const char **format, t_form *form)
{
	if (**format == '#')
		form->hash = 1;
	else if (**format == '0' && !form->precision_set)
		form->zero = 1;
	else if (**format == '-')
		form->minus = 1;
	else if (**format == '+')
		form->plus = 1;
	else if (**format == ' ')
		form->space = 1;
	else if (**format == 'L')
		form->upper_l = 1;
	else if (**format == 'l')
	{
		form->ll = (*(*format + 1) == 'l' ? 1 : 0);
		form->l = 1;
	}
	else if (**format == 'h')
	{
		form->hh = (*(*format + 1) == 'h' ? 1 : 0);
		form->h = 1;
	}
}

void	set_digit(const char **format, t_form *form)
{
	if (!form->precision_set)
		form->width = ft_atoi(*format);
	else
		form->precision = ft_atoi(*format);
}

t_form	parse(const char **format)
{
	t_form	form;

	form = (t_form){0};
	while (**format)
	{
		if (ft_isalpha(**format))
		{
			form.type = **format;
			return (form);
		}
		else if (ft_strchr(FLAGS, **format))
			set_flag(format, &form);
		else if (ft_isdigit(**format))
		{
			set_digit(format, &form);
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
		else if (**format == '.')
			form.precision_set = 1;
		(*format)++;
	}
	return (form);
}

void	dif_zero_manager(t_form form, char **src, char *new_str, int srclen)
{
	int i;

	i = 0;
	if (form.plus || form.space || **src == '-')
	{
		if (**src == '-')
			new_str[i++] = '-';
		else if (form.plus)
			new_str[i++] = '+';
		else if (form.space)
			new_str[i++] = ' ';
		while (i < form.width - srclen + 1)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], (*src + 1));
	}
	else
	{
		while (i < form.width - srclen)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], *src);
	}
	free(*src);
	*src = new_str;
}

void	hex_zero_manager(t_form form, char **src, char *new_str, int srclen)
{
	int i;

	i = 0;
	if (form.hash)
	{
		new_str[i++] = '0';
		new_str[i++] = form.type == 'x' ? 'x' : 'X';
		while (i < form.width - srclen + 2)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], (*src + 2));
	}
	else
	{
		while (i < form.width - srclen)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], *src);
	}
	free(*src);
	*src = new_str;
}

void	zero_manager(t_form form, char **src, char *new_str, int srclen)
{
	int i;

	i = 0;
	if (ft_strchr("dif", form.type))
		dif_zero_manager(form, src, new_str, srclen);
	else if ((form.type == 'x' || form.type == 'X'))
		hex_zero_manager(form, src, new_str, srclen);
	else if (form.type == 'u' || form.type == 'o')
	{
		while (i < form.width - srclen)
		{
			new_str[i] = '0';
			i++;
		}
		ft_strcpy(&new_str[i], *src);
		free(*src);
		*src = new_str;
	}
}

void	left_align_manager(char *new_str, char **src, int srclen, int width)
{
	ft_strcpy(new_str, *src);
	while (srclen < width)
		new_str[srclen++] = ' ';
	free(*src);
	*src = new_str;
}

void	right_align_manager(char *new_str, char **src, int srclen, int width)
{
	int		i;
	int		cpy_from;

	cpy_from = width - srclen;
	ft_strcpy(new_str + cpy_from, *src);
	i = 0;
	while (i < cpy_from)
		new_str[i++] = ' ';
	free(*src);
	*src = new_str;
}

void	width_manager(t_form form, char **src)
{
	int		srclen;
	int		width;
	char	*new_str;

	width = form.width;
	srclen = ft_strlen(*src);
	if (width <= srclen)
		return ;
	new_str = ft_strnew(width);
	if (form.minus)
		left_align_manager(new_str, src, srclen, width);
	else
	{
		if (ft_strchr("diouxXf", form.type) && form.zero
			&& (!form.precision_set || form.type == 'f'))
			zero_manager(form, src, new_str, srclen);
		else
			right_align_manager(new_str, src, srclen, width);
	}
}

void	prec_for_minus(t_form form, char **src)
{
	int		size;
	char	*new_str;
	char	*beginning;

	size = form.precision - ft_strlen(*src);
	if (size <= 0)
		return ;
	beginning = ft_strnew(size);
	while (--size >= 0)
		beginning[size] = '0';
	new_str = ft_strjoin(beginning, *src);
	free(*src);
	free(beginning);
	*src = new_str;
}

void	prec_without_minus(t_form form, char **src)
{
	int		size;
	char	*new_str;
	char	*beginning;

	size = form.precision - ft_strlen(*src) + 2;
	if (size <= 0)
		return ;
	beginning = ft_strnew(size);
	beginning[0] = '-';
	while (--size >= 1)
		beginning[size] = '0';
	new_str = ft_strjoin(beginning, (*src + 1));
	free(*src);
	free(beginning);
	*src = new_str;
}

void	precision_manager(t_form form, char **src)
{
	char	*to_free;
	int		size;

	if (form.type == 's' && form.precision_set
		&& form.precision < ft_strlen(*src))
	{
		to_free = *src;
		*src = ft_strsub(*src, 0, form.precision);
		free(to_free);
	}
	else if (ft_strchr("diouxX", form.type))
	{
		if (**src != '-')
			prec_for_minus(form, src);
		else
			prec_without_minus(form, src);
	}
}

void	plus_space_manager(t_form form, char **src)
{
	char *new_str;
	char ch;

	if (ft_strchr("dif", form.type) &&
		(form.space || form.plus) && **src != '-')
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
	if (form.hash)
	{
		if (form.type == 'o')
			new_str = ft_strjoin("0", *src);
		else if (form.type == 'x')
			new_str = ft_strjoin("0x", *src);
		else if (form.type == 'X')
			new_str = ft_strjoin("0X", *src);
		else if (form.type == 'f' && form.precision_set && form.precision == 0)
			new_str = ft_strjoin(*src, ".");
		if (new_str != NULL)
		{
			free(*src);
			*src = new_str;
		}
	}
}

char	*get_pointer_str(va_list args)
{
	int		i;
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

char	*get_decimal_str(t_form form, va_list args, int base)
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

char	*get_unsigned_str(t_form form, va_list args, int base)
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

char	*get_float_str(t_form form, va_list args)
{
	if (form.upper_l)
		return (ftoa(va_arg(args, long double),
			form.precision_set ? form.precision : 6));
	else
		return (ftoa(va_arg(args, double),
			form.precision_set ? form.precision : 6));
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
		result = get_decimal_str(form, args, base);
	else if (ft_strchr("uoxX", form.type))
		result = get_unsigned_str(form, args, base);
	else if (form.type == 'f')
		result = get_float_str(form, args);
	if (form.type == 'x')
	{
		i = -1;
		while (result[++i])
			result[i] = ft_tolower(result[i]);
	}
	return (result);
}

void	run_managers(t_form form, char **result)
{
	precision_manager(form, result);
	plus_space_manager(form, result);
	hash_manager(form, result);
	width_manager(form, result);
}

int		dispatcher(t_form form, va_list args)
{
	char	*result;
	int		printed;

	if (!ft_strchr(CONVERSIONS, form.type))
		return (0);
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
	run_managers(form, &result);
	ft_putstr(result);
	printed = ft_strlen(result);
	free(result);
	return (printed);
}

void	print_and_move(const char ch, int *printed)
{
	ft_putchar(ch);
	(*printed)++;
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_form	form;
	int		printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			print_and_move(*format, &printed);
		else
		{
			format++;
			if (*format == '%')
				print_and_move('%', &printed);
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
