#include "../../include/ft_printf.h"

void	ft_printf_percent(__attribute_maybe_unused__ va_list *args, int *len)
{
	fill_buffer(ft_c_to_s('%'), 0);
	(*len)++;
}
