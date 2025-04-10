/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:29:55 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/02/17 17:44:58 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			actlen;
	unsigned int	i;
	char			*substr;

	i = 0;
	actlen = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if ((size_t)len > ft_strlen(s) - start)
		substr = ft_calloc(ft_strlen(s) - start + 1, 1);
	else
		substr = ft_calloc(len + 1, 1);
	if (substr == NULL)
		return (NULL);
	i = start;
	actlen = 0;
	while (s[i] != '\0' && actlen < len)
		substr[actlen++] = (char) s[i++];
	return (substr);
}
