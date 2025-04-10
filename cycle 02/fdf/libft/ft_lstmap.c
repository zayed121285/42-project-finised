/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:56:58 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/24 15:32:46 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*newnode;
	t_list	*newliststart;

	current = lst;
	newliststart = NULL;
	while (current != NULL)
	{
		newnode = ft_lstnew((*f)(current->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newliststart, del);
			return (NULL);
		}
		ft_lstadd_back(&newliststart, newnode);
		current = current->next;
	}
	return (newliststart);
}
