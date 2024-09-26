#include "../../include/libft.h"

void	ft_memcheck(t_gc **ptrs, void *p, int side, char *file)
{
	t_gc	*lstnew;

	lstnew = ft_gcnew(p);
	if (lstnew == NULL)
	{
		ft_gcclear(ptrs);
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
	lstnew->file = file;
	if (side == BACK)
		ft_gcadd_back(ptrs, lstnew);
	else
		ft_gcadd_front(ptrs, lstnew);
	if ((file == NULL && p == NULL) || (file != NULL && *(int *)p == -1))
	{
		if (file == NULL)
			perror("Memory allocation failed");
		if (file != NULL)
			perror(file);
		ft_gcclear(ptrs);
		exit(EXIT_FAILURE);
	}
}
