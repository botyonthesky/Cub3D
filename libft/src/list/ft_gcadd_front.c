#include "../../include/libft.h"

void	ft_gcadd_front(t_gc **lst, t_gc *new)
{
	new->next = *lst;
	*lst = new;
}
