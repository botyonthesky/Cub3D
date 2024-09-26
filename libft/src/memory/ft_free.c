#include "../../include/libft.h"

void	ft_free(void *p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}
