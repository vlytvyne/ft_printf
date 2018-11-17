/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:51:06 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:51:08 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hash_manager(t_form form, char **src)
{
	char *new_str;

	new_str = NULL;
	if (form.hash)
	{
		if (form.type == 'o' && **src != '0')
			new_str = ft_strjoin("0", *src);
		else if (form.type == 'x' && **src != '0' && **src != '\0')
			new_str = ft_strjoin("0x", *src);
		else if (form.type == 'X' && **src != '0' && **src != '\0')
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
