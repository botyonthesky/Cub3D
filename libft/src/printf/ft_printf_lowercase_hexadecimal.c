#include "../../include/ft_printf.h"

void	ft_printf_lowercase_hex(va_list *args, int *len)
{
	long	n;

	n = va_arg(*args, int);
	if (n == 0)
	{
		fill_buffer(ft_c_to_s('0'), 0);
		(*len)++;
		return ;
	}
	if (n < 0)
		n = UINT_MAX + n + 1;
	ft_printf_convert(n, 16, "0123456789abcdef", len);
}
