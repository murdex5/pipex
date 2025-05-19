/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:14:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/08 11:19:56 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

static void	check_val(int hex_val, int *leading_zero, int *count)
{
	if (hex_val != 0 || !(*leading_zero))
	{
		ft_putchar_fd(hex_digit(hex_val), 1);
		(*count)++;
		(*leading_zero) = 0;
	}
}

int	ft_print_addr(void *p0)
{
	int			i;
	int			leading_zero;
	uintptr_t	p;
	int			hex_val;
	int			count;

	count = 2;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	p = (uintptr_t)p0;
	i = sizeof(p) * 8 - 4;
	leading_zero = 1;
	while (i >= 0)
	{
		hex_val = (p >> i) & 0xf;
		check_val(hex_val, &leading_zero, &count);
		i -= 4;
	}
	if (leading_zero)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

int	check_unsigned(va_list args)
{
	unsigned int	n;
	int				count;

	n = va_arg(args, unsigned int);
	count = count_unsigned_digits(n);
	ft_putnbr_fd_unsigned(n, 1);
	return (count);
}
