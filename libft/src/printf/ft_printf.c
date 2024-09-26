#include "../../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	void	(*func_ptr[128])(va_list *, int *len);

	setup_conversion_handler(func_ptr);
	len = 0;
	va_start(args, format);
	ft_process_format(format, &args, &len, func_ptr);
	va_end(args);
	fill_buffer("", 1);
	return (len);
}
