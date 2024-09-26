#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len + start > s_len)
		len = s_len - start;
	str = malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
