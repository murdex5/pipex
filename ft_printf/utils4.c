/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:39:13 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/07 13:39:15 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	count_digits(int nb)
{
	int	digits;

	digits = 0;
	if (nb <= 0)
	{
		++digits;
		nb = -nb;
	}
	while (nb != 0)
	{
		digits++;
		nb = nb / 10;
	}
	return (digits);
}

int	count_unsigned_digits(unsigned int nb)
{
	int	digits;

	digits = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		digits++;
		nb = nb / 10;
	}
	return (digits);
}

int	count_hex_digits(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}
