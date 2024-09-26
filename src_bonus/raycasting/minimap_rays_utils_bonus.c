/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:17:29 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 07:51:23 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/rays.h"

void	red_laser(t_game *game, struct s_rays *r)
{
	game->player.a = r->a;
	r->i = 0;
	r->x = game->player.x;
	r->y = game->player.y;
	vertical_ray(game, r);
	horizontal_ray(game, r);
	if (game->player.a == game->c * 180 || game->player.a == 0)
		vertical_point(game, r);
	if (game->player.a == game->c * 90 || game->player.a == game->c * 270)
		horizontal_point(game, r);
	if (r->r < r->r2)
	{
		game->player.wx = r->xn;
		game->player.wy = r->yn;
		draw_line(&game->minimap[0], &(t_line){r->x, r->y, r->xn, r->yn},
			0xFF0000);
	}
	else
	{
		game->player.wx = r->xn2;
		game->player.wy = r->yn2;
		draw_line(&game->minimap[0], &(t_line){r->x, r->y, r->xn2, r->yn2},
			0xFF0000);
	}
}

void	has_mob_in_sight(t_game *game, struct s_rays *r)
{
	if (abs(ft_mod(game->player.a, game->c * 360) - \
		ft_mod(r->a, game->c * 360)) <= 5)
	{
		if (game->map.rays_o[r->i] == 6 || game->map.rays_o[r->i] == 12)
		{
			if (game->map.rays_x[r->i] >= 2 && game->map.rays_x[r->i] <= 8)
			{
				game->player.mob_in_sight = 1;
			}
		}
	}
}
