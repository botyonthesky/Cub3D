#include "../../include/libft.h"

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token;
	char	*next_token;

	if (str != NULL)
		token = str;
	else if (*saveptr == NULL)
		return (NULL);
	else
		token = *saveptr;
	while (*token != '\0' && ft_strchr(delim, *token) != NULL)
		token++;
	if (*token == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	next_token = token + 1;
	while (*next_token != '\0' && ft_strchr(delim, *next_token) == NULL)
		next_token++;
	if (*next_token != '\0')
		*next_token++ = '\0';
	else
		next_token = NULL;
	*saveptr = next_token;
	return (token);
}
