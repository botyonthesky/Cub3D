#include "../../include/ft_printf.h"

void	ft_printf_integer_decimal(va_list *args, int *len)
{
	long	n;

	n = va_arg(*args, int);
	ft_printf_convert(n, 10, "0123456789", len);
}
