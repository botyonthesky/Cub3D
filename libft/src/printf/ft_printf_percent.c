#include "../../include/ft_printf.h"

void	ft_printf_percent(va_list *args, int *len)
{
	(void)args;
	fill_buffer(ft_c_to_s('%'), 0);
	(*len)++;
}
