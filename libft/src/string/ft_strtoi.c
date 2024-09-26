#include "../../include/libft.h"

static int	check_overflow(int *result, const char *str, char **endptr, \
	int sign)
{
	if (*result > INT_MAX / 10 || (*result == INT_MAX / 10 && (*str - '0') \
		> INT_MAX % 10))
	{
		*endptr = (char *)str;
		if (sign == 1)
			*result = INT_MAX;
		else
			*result = INT_MIN;
		return (1);
	}
	return (0);
}

int	ft_strtoi(const char *str, char **endptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (check_overflow(&result, str, endptr, sign) == 1)
			return (result);
		result = result * 10 + *str - '0';
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * sign);
}
