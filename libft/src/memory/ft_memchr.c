#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	char_c;

	char_c = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr == char_c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
