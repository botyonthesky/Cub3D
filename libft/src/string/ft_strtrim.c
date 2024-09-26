#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*str;

	start = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
		start++;
	if (start > len)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[len]))
		len--;
	str = malloc(sizeof(*str) * len - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + start), len - start + 2);
	return (str);
}
