#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	char_c;

	char_c = (unsigned char)c;
	ptr = s;
	while (n-- > 0)
		*ptr++ = char_c;
	return (s);
}
