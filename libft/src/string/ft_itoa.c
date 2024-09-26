#include "../../include/libft.h"

char	*ft_itoa(int n)
{
	static char	buf[12];
	char		*ptr;

	if (n == 0)
		return ("0");
	ptr = buf + 11;
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
