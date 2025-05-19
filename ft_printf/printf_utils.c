/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:05:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/07 12:05:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_chars(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c' || c == 's' || c == 'd')
		count = print_basic(c, args);
	else if (c == 'p')
		count = check_mem(args);
	else if (c == 'i' || c == 'u')
		count = print_number(c, args);
	else if (c == '%' || c == 'X' || c == 'x')
		count = print_hexes(c, args);
	else
	{
		ft_putchar_fd('?', 1);
		count = 1;
	}
	return (count);
}

int	count_first_param(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '%')
			{
				count++;
				str++;
			}
			else if (*(str + 1) == 'c' || *(str + 1) == 's' || *(str + 1) == 'd'
				|| *(str + 1) == 'p' || *(str + 1) == 'i' || *(str + 1) == 'u'
				|| *(str + 1) == 'x' || *(str + 1) == 'X')
			{
				str++;
			}
		}
		else
			count++;
		str++;
	}
	return (count);
}
