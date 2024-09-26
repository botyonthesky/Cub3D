#include "../../include/ft_printf.h"

void	ft_printf_unsigned_decimal(va_list *args, int *len)
{
	long	n;
	char	*nb;

	n = va_arg(*args, int);
	if (n < 0)
		n = UINT_MAX + n + 1;
	nb = ft_ltoa(n);
	*len += ft_strlen(nb);
	fill_buffer(nb, 0);
}
