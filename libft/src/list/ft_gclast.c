#include "../../include/libft.h"

t_gc	*ft_gclast(t_gc *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
