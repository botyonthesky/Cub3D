#include "../../include/libft.h"

long long	ft_atoll(const char *nptr)
{
	bool		neg;
	long long	nb;

	neg = false;
	while (((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
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
