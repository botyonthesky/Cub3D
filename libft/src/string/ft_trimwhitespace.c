#include "../../include/libft.h"

char	*ft_trimwhitespace(char *str, int side)
{
	char	*end;

	while (ft_isspace(*str))
		str++;
	if (*str == '\0' || side == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	end[1] = '\0';
	return (str);
}
