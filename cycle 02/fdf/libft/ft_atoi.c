/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:01 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/21 17:16:07 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ret_check(unsigned int i, int sign)
{
	if (i > 2147483647 && sign == 1)
		return (-1);
	if (i > 2147483648 && sign == -1)
		return (0);
	else
		return (i * sign);
}

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				found;
	int				sign;

	num = 0;
	found = 0;
	sign = 1;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			found = 1;
			num = (num * 10) + (*str - '0');
		}
		else if ((*str == '+' || *str == '-') && found == 0)
		{
			found = 1;
			sign = 44 - *str;
		}
		else if ((*str != ' ' && !(*str >= '\t' && *str <= '\r')
				&& found == 0) || found == 1)
			break ;
		str++;
	}
	return ((int) ret_check(num, sign));
}
