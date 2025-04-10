/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:08:06 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 17:23:20 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filefdf.h"

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
