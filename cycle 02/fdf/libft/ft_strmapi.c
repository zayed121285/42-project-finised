/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:38:46 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/24 07:39:17 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	ret[i] = '\0';
	while (i-- > 0)
		ret[i] = (*f)(i, s[i]);
	return (ret);
}
