#include "../../include/libft.h"

char	*ft_ltoa(long n)
{
	static char	buf[21];
	char		*ptr;

	if (n == 0)
		return ("0");
	ptr = buf + 20;
	if (n >= 0)
	{
		while (n != 0)
		{
			*--ptr = '0' + (n % 10);
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*--ptr = '0' - (n % 10);
			n /= 10;
		}
		*--ptr = '-';
	}
	return (ptr);
}
