/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:35:06 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/21 19:18:55 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	ret = malloc(i + 1);
	i = 0;
	while (s1[i])
	{
		ret[i] = ((char *)s1)[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
