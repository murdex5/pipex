/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:16:37 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/08 11:21:15 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd_unsigned(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
}
