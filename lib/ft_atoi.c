/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:59:31 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 13:32:04 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int sign;
	int res;

	res = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
	{
		sign = 1;
		if (*str == '+')
			str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
