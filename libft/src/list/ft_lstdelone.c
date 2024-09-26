#include "../../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst->content)
		del(lst->content);
	free(lst);
	lst = NULL;
}
