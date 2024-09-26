#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	char_c;

	str = (char *)s;
	char_c = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == char_c)
			return (str);
		str++;
	}
	if (char_c == 0)
		return (str);
	return (NULL);
}
