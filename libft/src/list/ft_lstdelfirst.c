#include "../../include/libft.h"

t_list	*ft_lstdelfirst(t_list *lst, void (*del)(void *))
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	lst = lst->next;
	current->next = NULL;
	del(current->content);
	free(current);
	return (lst);
}
