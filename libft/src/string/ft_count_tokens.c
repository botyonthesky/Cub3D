#include "../../include/libft.h"

int	count_tokens(char *str, char *sep)
{
	int		count;
	int		i;

	count = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(sep, str[i]) != NULL)
			count++;
		i++;
	}
	return (count);
}
