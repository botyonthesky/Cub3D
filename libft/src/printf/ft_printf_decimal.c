#include "../../include/ft_printf.h"

void	ft_printf_decimal(va_list *args, int *len)
{
	int		n;
	char	*nb;

	n = va_arg(*args, int);
	nb = ft_itoa(n);
	*len += ft_strlen(nb);
	fill_buffer(nb, 0);
}
