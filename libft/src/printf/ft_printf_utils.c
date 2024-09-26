#include "../../include/ft_printf.h"

void	fill_buffer(char *str, int release)
{
	static char	buffer[256];
	static char	*bufptr = buffer;
	static int	len = 0;

	if (release == 1)
	{
		buffer[len] = '\0';
		ft_putstr_fd(buffer, 1);
		bufptr = buffer;
		len = 0;
	}
	while (*str != '\0')
	{
		*bufptr++ = *str++;
		if (len == 254 || buffer[len] == '\n' || buffer[len] == '\0')
		{
			buffer[len + 1] = '\0';
			ft_putstr_fd(buffer, 1);
			bufptr = buffer;
			len = 0;
		}
		else
			len++;
	}
}

void	setup_conversion_handler(void (*handler_lst[128])(va_list *, int *len))
{
	ft_bzero(handler_lst, sizeof(void *) * 128);
	handler_lst[(int) 'c'] = ft_printf_char;
	handler_lst[(int) 's'] = ft_printf_string;
	handler_lst[(int) 'd'] = ft_printf_decimal;
	handler_lst[(int) 'u'] = ft_printf_unsigned_decimal;
	handler_lst[(int) 'i'] = ft_printf_integer_decimal;
	handler_lst[(int) 'p'] = ft_printf_address;
	handler_lst[(int) 'x'] = ft_printf_lowercase_hex;
	handler_lst[(int) 'X'] = ft_printf_uppercase_hex;
	handler_lst[(int) '%'] = ft_printf_percent;
}

void	ft_handle_negative_and_zero(long long *n, int *len, char *base_set)
{
	if (*n < 0)
	{
		fill_buffer(ft_c_to_s('-'), 0);
		*n = -(*n);
		(*len)++;
	}
	if (*n == 0)
	{
		fill_buffer(ft_c_to_s(base_set[0]), 0);
		(*len)++;
	}
}

void	ft_printf_convert(long long n, int base, char *base_set, int *len)
{
	int		i;
	int		j;
	char	temp;
	char	output[20];

	i = 0;
	j = 0;
	ft_handle_negative_and_zero(&n, len, base_set);
	while (n > 0)
	{
		output[i++] = base_set[n % base];
		n /= base;
	}
	output[i] = '\0';
	while (i - j > i / 2)
	{
		temp = output[j];
		output[j] = output[i - 1 - j];
		output[i - 1 - j++] = temp;
	}
	*len += ft_strlen(output);
	fill_buffer(output, 0);
}

void	ft_process_format(const char *format, va_list *args, int *len, \
void (**func_ptr)(va_list *, int *))
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (func_ptr[(int)*format] != NULL)
				func_ptr[(int)*format](args, len);
			else
			{
				fill_buffer(ft_c_to_s('%'), 0);
				(*len)++;
			}
		}
		else
		{
			fill_buffer(ft_c_to_s(*format), 0);
			(*len)++;
		}
		format++;
	}
}
