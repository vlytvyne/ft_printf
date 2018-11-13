/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:03:51 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 16:24:27 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#define ARGS "Artur idet w shkolu\n"

int		main(void)
{
	printf("Printf:\n");
	printf(ARGS);
	printf("FT_printf:\n");
	ft_printf(ARGS);
}
