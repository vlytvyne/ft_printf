/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:42:53 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 14:42:55 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>

# define CONVERSIONS "cspdiouxXf"
# define FLAGS "hlL#0-+ "

typedef struct		s_form
{
	unsigned int	hash:1;
	unsigned int	zero:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	l:1;
	unsigned int	ll:1;
	unsigned int	h:1;
	unsigned int	hh:1;
	unsigned int	upper_l:1;
	unsigned int	width;
	unsigned int	precision;
	char			type;
}					t_form;

int					ft_printf(const char *format, ...);

#endif
