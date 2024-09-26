#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	msize;
	void	*ptr;

	msize = nmemb * size;
	if (nmemb != 0 && msize / nmemb != size)
		return (NULL);
	ptr = malloc(msize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, msize);
	return (ptr);
}
