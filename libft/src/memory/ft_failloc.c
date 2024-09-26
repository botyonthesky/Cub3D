#include "../../include/libft.h"

void	ft_failloc(void *p)
{
	if (p == NULL)
	{
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
}
