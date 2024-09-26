#include "../../include/libft.h"

void	ft_gcdelone(t_gc **gc, void *p)
{
	t_gc	*current;
	t_gc	*prev;

	current = *gc;
	prev = NULL;
	if (current->content == p)
	{
		*gc = current->next;
		current->next = NULL;
		ft_gcclear(&current);
		current = *gc;
	}
	while (current != NULL && current->content != p)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	current->next = NULL;
	ft_gcclear(&current);
	current = NULL;
}
