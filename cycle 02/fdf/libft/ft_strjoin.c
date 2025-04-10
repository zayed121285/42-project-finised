/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:07:33 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/21 15:07:43 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len = ft_strlen(s2);
	ret = malloc(i + ++len);
	if (ret == NULL)
		return (NULL);
	while (--len >= 0)
		ret[i + len] = s2[len];
	while (--i >= 0)
		ret[i] = s1[i];
	return (ret);
}
