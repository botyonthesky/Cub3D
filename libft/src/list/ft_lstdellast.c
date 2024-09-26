#include "../../include/libft.h"

void	ft_lstdellast(t_list *lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = lst;
	if (current == NULL)
		return ;
	next = current->next;
	if (next != NULL)
	{
		while (next->next != NULL)
		{
			current = next;
			next = next->next;
		}
	}
	del(next->content);
	free(next);
	current->next = NULL;
}
