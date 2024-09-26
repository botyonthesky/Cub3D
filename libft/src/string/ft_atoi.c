#include "../../include/libft.h"

int	ft_atoi(const char *nptr)
{
	bool	neg;
	long	nb;

	neg = false;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		neg = true;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	nb = 0;
	while (ft_isdigit(*nptr))
		nb = (nb * 10) + (*nptr++ - '0');
	if (neg)
		return (-nb);
	return (nb);
}
