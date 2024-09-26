#include "../../include/libft.h"

int	ft_rgb_to_hex(t_color c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}
