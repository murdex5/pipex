/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:34:06 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/30 13:34:08 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	check_str(va_list args)
{
	char	*str;
	int		count;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	if (str == (void *)0)
		return (0);
	count = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}

int	check_mem(va_list args)
{
	void	*p;
	int		count;

	p = va_arg(args, void *);
	if (p == (void *)0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = ft_print_addr(p);
	return (count);
}

int	check_num(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = count_digits(num);
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (count);
	}
	ft_putnbr_fd(num, 1);
	return (count);
}

int	check_int(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = count_digits(num);
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (count);
	}
	ft_putnbr_fd(num, 1);
	return (count);
}
