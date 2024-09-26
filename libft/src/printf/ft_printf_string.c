#include "../../include/ft_printf.h"

void	ft_printf_string(va_list *args, int *len)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
	{
		fill_buffer("(null)", 0);
		*len += 6;
	}
	else
	{
		fill_buffer(str, 0);
		*len += ft_strlen(str);
	}
}
