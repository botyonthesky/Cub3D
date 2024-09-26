#include "../../include/libft.h"

void	close_fd(t_gc **p, int fd)
{
	if (close(fd) == -1)
	{
		perror(ft_itoa(fd));
		ft_gcclear(p);
		exit(EXIT_FAILURE);
	}
}
