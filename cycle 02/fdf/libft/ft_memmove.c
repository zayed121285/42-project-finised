/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:35:58 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/24 14:29:35 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*dst;
	char	*sr;

	dst = (char *) dest;
	sr = (char *) src;
	i = -1;
	if (src != dest)
	{
		if (dst <= sr)
		{
			while (++i < len)
				dst[i] = sr[i];
		}
		else
		{
			while (len-- > 0)
				dst[len] = sr[len];
		}
	}
	return (dest);
}
