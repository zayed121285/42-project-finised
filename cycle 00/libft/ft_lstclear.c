
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nxt;

	nxt = *lst;
	while (nxt != NULL)
	{
		current = nxt;
		nxt = nxt->next;
		(*del)(current->content);
		free(current);
	}
	*lst = NULL;
}
