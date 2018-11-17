/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:03:51 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 19:26:05 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include "libft.h"

int		main(void)
{
	int *b;
	b = malloc(10);
	*b = 10;
	ft_printf("%#010X\n", 15);
	printf("%#010X\n", 15);
	// printf("1C:%-5c\n", 'a');
	// printf("2S:%4.7s\n", "Miami Police");
	// printf("3S:%4.7s\n", "KO");
	// printf("4P:%20p\n", b);
	// printf("5D:%010.4d\n", 11);
	// printf("6D:%-10.4d\n", 12);
	// printf("7D:%-.4d\n", 13);
	// printf("8D:%-.4d\n", -14);
	// printf("10D:%+10.d\n", 0);
	// printf("11I:% i\n", 15);
	// printf("12O:%#4o\n", 15);
	// printf("13U:%.4u\n", 10);
	// printf("14x:%#x\n", 122);
	// printf("15X:%#X\n", 122);
	// printf("16F:%# 010.f\n", 1234.2);
	// printf("17F:%3.4f\n", 1234.2);
	// printf("18F:%# 10f\n", 1.123456789);
	// printf("18F:%# 10.f\n", 1.123456789);
	// printf("18F:%# 10.5f\n", 1.123456789);
 //    printf("19S%6.3s\n", "12345678");
 //    ft_printf("FT 1C:%-5c\n", 'a');
	// ft_printf("FT 2S:%4.7s\n", "Miami Police");
	// ft_printf("FT 3S:%4.7s\n", "KO");
	// ft_printf("FT 4P:%20p\n", b);
	// ft_printf("FT 5D:%010.4d\n", 11);
	// ft_printf("FT 6D:%-10.4d\n", 12);
	// ft_printf("FT 7D:%-.4d\n", 13);
	// ft_printf("FT 8D:%-.4d\n", -14);
	// ft_printf("FT 10D:%+10.d\n", 0);
	// ft_printf("FT 11I:% i\n", 15);
	// ft_printf("FT 12O:%#4o\n", 15);
	// ft_printf("FT 13U:%.4u\n", 10);
	// ft_printf("FT 14x:%#x\n", 122);
	// ft_printf("FT 15X:%#X\n", 122);
	// ft_printf("FT 16F:%# 010.f\n", 1234.2);
	// ft_printf("FT 17F:%3.4f\n", 1234.2);
	// ft_printf("FT 18F:%# 10f\n", 1.123456789);
	// ft_printf("FT 18F:%# 10.f\n", 1.123456789);
	// ft_printf("FT 18F:%# 10.5f\n", 1.123456789);
 //    ft_printf("FT 19S%6.3s\n", "12345678");
	// printf("X%#.7X\n", 15);
	// ft_printf("FT X%#.7X\n", 15);
	//system("leaks a.out");
}