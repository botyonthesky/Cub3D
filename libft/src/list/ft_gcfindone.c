#include "../../include/libft.h"

t_gc	*ft_gcfindone(t_gc **gc, void *p)
{
	t_gc	*current;

	current = *gc;
	while (current != NULL && current->content != p)
		current = current->next;
	if (current == NULL)
		return (NULL);
	return (current);
}
