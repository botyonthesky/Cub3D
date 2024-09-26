#include "../../include/libft.h"

void	ft_gcclear(t_gc **lst)
{
	t_gc	*ptr;
	t_gc	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		if (ptr->content != NULL && ptr->file == NULL)
		{
			free(ptr->content);
			ptr->content = NULL;
		}
		if (ptr->content != NULL && ptr->file != NULL)
		{
			if (*(int *)ptr->content != -1)
				get_next_line(*(int *)ptr->content, 1);
			if (*(int *)ptr->content != -1)
				close(*(int *)ptr->content);
		}
		free(ptr);
		ptr = NULL;
		ptr = next;
	}
	*lst = NULL;
}
