#include "../../include/libft.h"

void	dup_error(t_gc **ptrs, int fd)
{
	if (fd == -1)
	{
		ft_gcclear(ptrs);
		perror("dup error");
		exit(EXIT_FAILURE);
	}
}
