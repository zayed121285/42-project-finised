/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:09:21 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/24 15:27:06 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*dev)(void *))
{
	t_list		*str;
	t_list		*keep;

	str = *lst;
	if (!*lst || !dev)
		return ;
	while (str != NULL)
	{
		keep = str;
		str = str->next;
		dev(keep->content);
		free(keep);
	}
	*lst = NULL;
}
