#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	char			*str;
	unsigned char	char_c;

	ptr = 0;
	str = (char *)s;
	char_c = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == char_c)
			ptr = str;
		str++;
	}
	if (!ptr && c != '\0')
		return (NULL);
	else if (c == '\0')
		return (str);
	return (ptr);
}
