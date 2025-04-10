/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:51:50 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/21 14:52:07 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*st;

	st = (void *) s;
	if (n <= 0)
		return (NULL);
	while (n-- > 0)
	{
		if (*st == (char) c)
			return ((void *) s);
		st++;
		s++;
	}
	return (NULL);
}
