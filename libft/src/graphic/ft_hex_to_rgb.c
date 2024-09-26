#include "../../include/libft.h"

t_color	ft_hex_to_rgb(int color)
{
	t_color	rgb;

	rgb.c = color;
	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}
