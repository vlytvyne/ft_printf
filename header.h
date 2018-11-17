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

# include <stdarg.h>
# include "libft.h"

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
	unsigned int	precision_set:1;
	unsigned int	width;
	unsigned int	precision;
	char			type;
}					t_form;

int					ft_printf(const char *format, ...);
t_form				parse(const char **format);
char				*get_num_str(t_form form, va_list args);
void				precision_manager(t_form form, char **src);
void				width_manager(t_form form, char **src);
void				hash_manager(t_form form, char **src);
void				plus_space_manager(t_form form, char **src);
void				zero_manager(t_form form, char **src,
					char *new_str, int srclen);

#endif
