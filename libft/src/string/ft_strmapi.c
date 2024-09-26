#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	map = ft_calloc(ft_strlen(s) + 1, sizeof(*map));
	if (!map)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		map[i] = f(i, s[i]);
		i++;
	}
	return (map);
}
