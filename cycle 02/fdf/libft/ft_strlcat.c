/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:13:52 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/21 15:14:40 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = ft_strlen(dst);
	count = ft_strlen(src);
	len = i;
	if (len > dstsize)
		return (count + dstsize);
	if (dstsize - len > 0)
	{
		while (*src != '\0' && i < (dstsize - 1))
		{
			dst[i++] = *src;
			src++;
		}
	}
	dst[i] = '\0';
	return (len + count);
}
