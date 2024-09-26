/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:44:54 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 08:27:22 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/rays.h"

bool	horizontal_point(t_game *game, struct s_rays *r)
{
	int	tex;

	r->n = 0;
	while (1)
	{
		r->yn = r->y + 16 - fmod(r->y, 16) + 16 * r->n;
		if (game->player.a == game->c * 270)
			r->yn = r->y - 16 - fmod(r->y, 16) + 16 * (-r->n + 1);
		r->xn = r->x + ((r->yn - r->y) / game->sin_t[game->player.a])
			* game->cos_t[game->player.a];
		tex = is_an_horizontal_wall(game, r->xn, r->yn);
		if (tex > 0)
		{
			r->r = (r->yn - r->y) / game->sin_t[game->player.a];
			r->r2 = r->r + 1;
			r->o = 1;
			if (game->player.a == game->c * 270)
				r->o = 0;
			if (tex >= 2)
				r->o = tex + 3;
			return (true);
		}
		r->n++;
	}
}

bool	vertical_point(t_game *game, struct s_rays *r)
{
	int	tex;

	r->n = 0;
	while (1)
	{
		r->xn2 = r->x + 16 - fmod(r->x, 16) + 16 * r->n;
		if (game->player.a == game->c * 180)
			r->xn2 = r->x - fmod(r->x, 16) + 16 * -r->n;
		r->yn2 = r->y + ((r->xn2 - r->x) / game->cos_t[game->player.a])
			* game->sin_t[game->player.a];
		tex = is_a_vertical_wall(game, r->xn2, r->yn2);
		if (tex > 0)
		{
			r->r2 = (r->xn2 - r->x) / game->cos_t[game->player.a];
			r->r = r->r2 + 1;
			r->o2 = 3;
			if (game->player.a == game->c * 180)
				r->o2 = 2;
			if (tex >= 2)
				r->o2 = tex + 3;
			return (true);
		}
		r->n++;
	}
}

void	vertical_ray(t_game *game, struct s_rays *r)
{
	int	tex;

	r->n = 0;
	while (1)
	{
		r->xn = r->x + 16 - fmod(r->x, 16) + 16 * r->n;
		if (game->player.a > game->c * 90 && game->player.a < game->c * 270)
			r->xn = r->x - fmod(r->x, 16) + 16 * -r->n;
		if (game->player.a == game->c * 90 || game->player.a == game->c * 270)
			break ;
		else
			r->yn = r->y + ((r->xn - r->x)
					/ game->cos_t[game->player.a])
				* game->sin_t[game->player.a];
		tex = is_a_vertical_wall(game, r->xn, r->yn);
		r->o = 3;
		if (game->player.a > game->c * 90 && game->player.a < game->c * 270)
			r->o = 2;
		if (tex > 1 || tex < 0)
			r->o = tex + 3;
		r->r = (r->xn - r->x) / game->cos_t[game->player.a];
		if (tex != 0)
			break ;
		r->n++;
	}
}

void	horizontal_ray(t_game *game, struct s_rays *r)
{
	int	tex;

	r->n = 0;
	while (1)
	{
		r->yn2 = r->y + 16 - fmod(r->y, 16) + 16 * r->n;
		if (game->player.a > game->c * 180)
			r->yn2 = r->y - fmod(r->y, 16) + 16 * -r->n;
		if (game->player.a == game->c * 180 || game->player.a == 0)
			break ;
		else
			r->xn2 = r->x + ((r->yn2 - r->y)
					/ game->sin_t[game->player.a])
				* game->cos_t[game->player.a];
		tex = is_an_horizontal_wall(game, r->xn2, r->yn2);
		r->o2 = 1;
		if (tex == 1 && game->player.a > game->c * 180)
			r->o2 = 0;
		if (tex > 1 || tex < 0)
			r->o2 = tex + 3;
		r->r2 = (r->yn2 - r->y) / game->sin_t[game->player.a];
		r->n++;
		if (tex != 0)
			break ;
	}
}

void	draw_minimap_rays(t_game *game)
{
	struct s_rays	r;

	r.a = game->player.a;
	game->player.mob_in_sight = 0;
	game->player.a = ft_mod(game->player.a - game->c * 29, game->c * 360);
	r.i = 0;
	r.x = game->player.x;
	r.y = game->player.y;
	while (game->player.a != ft_mod(r.a + game->c * 31, game->c * 360))
	{
		vertical_ray(game, &r);
		horizontal_ray(game, &r);
		if (game->player.a == game->c * 180 || game->player.a == 0)
			vertical_point(game, &r);
		if (game->player.a == game->c * 90 || game->player.a == game->c * 270)
			horizontal_point(game, &r);
		draw_rays(game, &r);
		has_mob_in_sight(game, &r);
		game->player.a = ft_mod(game->player.a + 2, game->c * 360);
		r.i++;
	}
	red_laser(game, &r);
}
