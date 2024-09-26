#include "../../include/libft.h"

t_gc	*ft_gcdelfirst(t_gc *lst)
{
	t_gc	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	lst = lst->next;
	current->next = NULL;
	free(current->content);
	current->content = NULL;
	free(current);
	return (lst);
}
