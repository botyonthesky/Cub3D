#include "../../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	n;
	int	len;

	n = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[n] != '\0')
	{
		len = 0;
		while (haystack[n + len] == needle[len])
		{
			if (needle[len + 1] == '\0')
				return ((char *)&haystack[n]);
			len++;
		}
		n++;
	}
	return (0);
}
