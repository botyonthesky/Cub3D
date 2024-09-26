#include "../../include/libft.h"

void	reopen(t_gc **p, int *fd)
{
	t_gc	*gc;

	gc = ft_gcfindone(p, fd);
	if (gc == NULL)
		return ;
	if (*(int *)gc->content != -1)
	{
		get_next_line(*(int *)gc->content, 1);
		close_fd(p, *(int *)gc->content);
	}
	*fd = open(gc->file, O_RDONLY);
	if (*fd == -1)
	{
		perror(gc->file);
		ft_gcclear(p);
		exit(EXIT_FAILURE);
	}
	gc->content = fd;
}
