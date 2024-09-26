#include "../../include/ft_printf.h"

void	ft_printf_convert_p(unsigned long n, int base, char *baseset, int *len)
{
	int		i;
	int		j;
	char	temp;
	char	output[20];

	i = 0;
	j = 0;
	if (n == 0)
		fill_buffer(ft_c_to_s(baseset[0]), 0);
	if (n == 0)
		(*len)++;
	while (n > 0)
	{
		output[i++] = baseset[n % base];
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

//VOID * POINTER ARGUMENT HAS TO BE PRINTED IN HEXADECIMAL FORMAT
void	ft_printf_address(va_list *args, int *len)
{
	void	*addr;

	addr = va_arg(*args, void *);
	if (addr == 0)
	{
		fill_buffer("(nil)", 0);
		*len += 5;
	}
	else
	{
		fill_buffer("0x", 0);
		*len += 2;
		ft_printf_convert_p((unsigned long)addr, 16, "0123456789abcdef", len);
	}
}
