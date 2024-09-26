#include "../../include/libft.h"

int	ft_is_prime(int nb)
{
	unsigned int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	if (nb % 6 == 5 || nb % 6 == 1)
	{
		while (i <= (unsigned int)nb / i)
		{
			if (nb % i == 0 || nb % (i + 2) == 0)
				return (0);
			i += 6;
		}
	}
	return (1);
}
