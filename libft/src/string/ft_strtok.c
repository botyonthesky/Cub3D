#include "../../include/libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*token = NULL;
	static char	*next_token = NULL;

	if (str != NULL)
		token = str;
	else if (next_token == NULL)
		return (NULL);
	else
		token = next_token;
	while (*token != '\0' && ft_strchr(delim, *token) != NULL)
		token++;
	if (*token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	next_token = token + 1;
	while (*next_token != '\0' && ft_strchr(delim, *next_token) == NULL)
		next_token++;
	if (*next_token != '\0')
		*next_token++ = '\0';
	else
		next_token = NULL;
	return (token);
}
