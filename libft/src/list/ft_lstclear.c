#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		if (ptr->content != NULL)
			del(ptr->content);
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}
