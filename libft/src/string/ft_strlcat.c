#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size > dst_len + src_len + 1)
		size = dst_len + src_len + 1;
	if (size <= dst_len || size == 0)
		return (src_len + size);
	else if (size != 0)
	{
		ft_memcpy(dst + dst_len, src, size - dst_len - 1);
		dst[size - 1] = '\0';
	}
	return (src_len + dst_len);
}
