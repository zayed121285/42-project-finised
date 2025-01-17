
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
