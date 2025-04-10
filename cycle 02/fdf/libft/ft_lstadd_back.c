/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:59:03 by zsid-ele          #+#    #+#             */
/*   Updated: 2024/12/24 15:26:58 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*move;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	move = *lst;
	while (move->next != NULL)
	{
		move = move->next;
	}
	move->next = new;
}
