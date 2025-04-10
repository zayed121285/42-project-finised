/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:35:04 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/06 10:49:13 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr(int num, int *ret_val)
{
	if (num < 0)
	{
		ft_putchar('-', ret_val);
		if (num == -2147483648)
		{
			ft_putchar('2', ret_val);
			ft_putnbr(147483648, ret_val);
			return ;
		}
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10, ret_val);
	ft_putchar(num % 10 + 48, ret_val);
}

void	ft_putchar(char c, int *ret_val)
{
	*ret_val += write(1, &c, 1);
}

void	ft_putstr(char *s, int *ret_val)
{
	if (!s)
	{
		ft_putstr("(null)", ret_val);
		return ;
	}
	while (*s)
		*ret_val += write(1, s++, 1);
}

static int	ft_controller(char ch, va_list list, int *ret_val)
{
	if (ch == 'c')
		ft_putchar(va_arg(list, int), ret_val);
	else if (ch == 's')
		ft_putstr(va_arg(list, char *), ret_val);
	else if (ch == 'd')
		ft_putnbr(va_arg(list, int), ret_val);
	else if (ch == 'i')
		ft_putnbr(va_arg(list, int), ret_val);
	else if (ch == 'u')
		ft_putunbr(va_arg(list, unsigned int), ret_val);
	else if (ch == 'x')
		ft_putstr(ft_convert(va_arg(list, unsigned int),
				"0123456789abcdef"), ret_val);
	else if (ch == 'X')
		ft_putstr(ft_convert(va_arg(list, unsigned int),
				"0123456789ABCDEF"), ret_val);
	else if (ch == 'p')
		ft_putptr(va_arg(list, unsigned long), ret_val);
	else if (ch == '%')
		ft_putchar('%', ret_val);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		is_empty;
	int		ret_val;

	ret_val = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			is_empty = 0;
			while (*(++str) == 32)
				is_empty = 1;

			if (is_empty)
				ft_putchar(' ', &ret_val);
			if (ft_controller(*str, list, &ret_val) != 0)
				ret_val = ret_val + write(1, str, 1);
		}
		else
			ret_val += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (ret_val);
}
