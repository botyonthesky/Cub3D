#include "../../include/libft.h"

void	ft_gcadd_back(t_gc **lst, t_gc *new)
{
	t_gc	*lstlast;

	if (*lst == NULL)
		*lst = new;
	else
	{
		lstlast = ft_gclast(*lst);
		lstlast->next = new;
	}
}
