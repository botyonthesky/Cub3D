#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *format, ...);
void	setup_conversion_handler(void (*handler_lst[128])(va_list *, int *len));
void	ft_handle_negative_and_zero(long long *n, int *len, char *base_set);
void	ft_process_format(const char *format, va_list *args, int *len, \
void (**func_ptr)(va_list *, int *));
void	ft_printf_convert(long long n, int base, char *base_set, int *len);
void	ft_printf_convert_p(unsigned long n, int base, char *baseset, int *len);
void	ft_printf_char(va_list *args, int *len);
void	ft_printf_string(va_list *args, int *len);
void	ft_printf_address(va_list *args, int *len);
void	ft_printf_decimal(va_list *args, int *len);
void	ft_printf_integer_decimal(va_list *args, int *len);
void	ft_printf_unsigned_decimal(va_list *args, int *len);
void	ft_printf_lowercase_hex(va_list *args, int *len);
void	ft_printf_uppercase_hex(va_list *args, int *len);
void	ft_printf_percent(va_list *args, int *len);
void	fill_buffer(char *str, int release);

#endif