#include "../../include/ft_printf.h"

void	ft_printf_char(va_list *args, int *len)
{
	int	c;

	c = va_arg(*args, int);
	if (c == 0)
	{
		fill_buffer("", 1);
		ft_putchar_fd(0, 1);
	}
	else
		fill_buffer(ft_c_to_s(c), 0);
	(*len)++;
}
