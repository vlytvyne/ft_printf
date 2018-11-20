/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:46 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/16 12:34:06 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		power(long long int num, int pow)
{
	long long int multiplier;

	multiplier = num;
	if (pow == 0 || num == 1)
		return (1);
	while (pow > 1)
	{
		num *= multiplier;
		pow--;
	}
	return (num);
}
