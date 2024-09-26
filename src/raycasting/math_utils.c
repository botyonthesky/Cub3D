#include "../../include/cub3d.h"

void	trig_tables(t_gc **p, t_game *game)
{
	float	*cos_t;
	float	*sin_t;
	float	rad_angle;
	float	rad;
	int		i;

	rad = (M_PI / (game->c * 180));
	cos_t = malloc(sizeof(*cos_t) * (game->c * 360 + 1));
	ft_memcheck(p, cos_t, FRONT, NULL);
	sin_t = malloc(sizeof(*sin_t) * (game->c * 360 + 1));
	ft_memcheck(p, sin_t, FRONT, NULL);
	i = 0;
	rad_angle = -rad;
	while (i < game->c * 360)
	{
		rad_angle += rad;
		cos_t[i] = cos(rad_angle);
		sin_t[i] = sin(rad_angle);
		i++;
	}
	game->cos_t = cos_t;
	game->sin_t = sin_t;
}

bool	is_inside_circle(t_circle *c)
{
	int	dx;
	int	dy;

	dx = c->x - c->cx;
	dy = c->y - c->cy;
	return (dx * dx + dy * dy <= c->r * c->r);
}
