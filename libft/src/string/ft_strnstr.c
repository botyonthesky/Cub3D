#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*b;

	b = (char *)big;
	if (!(*little))
		return (b);
	little_len = ft_strlen(little);
	while (*b && little_len <= len--)
	{
		if (*b == *little && (!(ft_strncmp(b, little, little_len))))
			return (b);
		b++;
	}
	return (NULL);
}
