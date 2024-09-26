#include "../../include/libft.h"

int	ft_isnumber(const char *nptr)
{
	if (*nptr == '\0')
		return (0);
	if (*nptr == '-')
	{
		nptr++;
		if (*nptr == '\0')
			return (0);
	}
	while (*nptr != '\0')
	{
		if (ft_isdigit(*nptr))
			nptr++;
		else
			return (0);
	}
	return (1);
}
