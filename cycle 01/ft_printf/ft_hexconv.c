/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:30:49 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/01/14 11:05:56 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long num, int *ret_val)
{
	if (num == 0)
	{
		ft_putstr("0x0", ret_val);
		return ;
	}
	ft_putstr("0x", ret_val);
	ft_putstr(ft_convert(num, "0123456789abcdef"), ret_val);
}

char	*ft_convert(size_t num, char *repres)
{
	static char	buffer[50];
	char		*ptr;
	int			base;

	base = ft_strlen(repres);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = repres[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = repres[num % base];
		num /= base;
	}
	return (ptr);
}

void	ft_putunbr(unsigned int num, int *ret_val)
{
	char	s[10];
	int		i;

	i = 0;
	if (num == 0)
		ft_putchar('0', ret_val);
	while (num)
	{
		s[i++] = num % 10 + '0';
		num /= 10;
	}
	while (i--)
		ft_putchar(*(s + i), ret_val);
}
