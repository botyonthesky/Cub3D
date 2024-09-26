#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_ptr;
	char		*dest_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	while (n-- > 0)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}
