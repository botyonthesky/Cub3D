#include "../../include/libft.h"

size_t	ft_strlen(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != '\0')
		ptr++;
	return (ptr - s);
}
