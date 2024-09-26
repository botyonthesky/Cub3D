#include "../../include/libft.h"

void	ft_gcdellast(t_gc *lst)
{
	t_gc	*current;
	t_gc	*next;

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
	free(next->content);
	next->content = NULL;
	free(next);
	current->next = NULL;
}
