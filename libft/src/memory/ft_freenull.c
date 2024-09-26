#include "../../include/libft.h"

void	ft_freenull(void **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
