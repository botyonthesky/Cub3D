#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = malloc(len * sizeof(*str));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	return (str);
}
