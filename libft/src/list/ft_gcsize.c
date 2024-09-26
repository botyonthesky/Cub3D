#include "../../include/libft.h"

int	ft_gcsize(t_gc *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
