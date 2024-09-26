/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:43:52 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 07:50:26 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_player_circle(t_game *game)
{
	draw_circle(&game->minimap[0], &(t_circle){game->player.x,
		game->player.y, 0, 0, 2}, 0xFF0000);
	draw_circle(&game->minimap[0], &(t_circle){game->player.x,
		game->player.y, 0, 0, 1}, 0xFF0000);
	draw_circle(&game->minimap[0], &(t_circle){game->player.x,
		game->player.y, 0, 0, 0}, 0xFF0000);
}

void	draw_minimap_grid(t_game *game)
{
	t_line	l;
	int		i;

	i = 0;
	while (i < game->map.size)
	{
		l.x1 = (i % game->map.width) * 16;
		l.y1 = (i / game->map.width) * 16;
		l.x2 = l.x1 + 16;
		l.y2 = l.y1 + 16;
		if (game->map.grid[i] == 1)
			draw_square(&game->minimap[0], &l, 0xFFFFFF, 1);
		else if (game->map.grid[i] == 2)
			draw_square(&game->minimap[0], &l, 0xBBBBBB, 1);
		else if (game->map.grid[i] == 3 || game->map.grid[i] == 9)
			draw_square(&game->minimap[0], &l, 0xFF0000, 1);
		else if (game->map.grid[i] != 1)
			draw_square(&game->minimap[0], &l, 0x000000, 1);
		l.x1 -= 16;
		draw_square(&game->minimap[0], &l, 0x777777, 0);
		i++;
	}
	draw_square(&game->minimap[0], &(t_line){0, 0, game->minimap[0].w - 1,
		game->minimap[0].h - 1}, 0x777777, 0);
}

void	circle_minimap(t_game *game)
{
	int	color;
	int	x;
	int	y;

	y = -HMMAP;
	while (y < HMMAP)
	{
		x = -HMMAP;
		while (x < HMMAP)
		{
			color = mlx_get_pixel_color(&game->minimap[0], game->player.x + x,
					game->player.y + y);
			my_mlx_pixel_put(&game->minimap[1], x + HMMAP, y + HMMAP, color);
			x++;
		}
		y++;
	}
	draw_outer_circle(&game->minimap[1], &(t_circle){HMMAP, HMMAP, 0, 0, HMMAP},
		0xff000000);
}

void	draw_minimap(t_game *game)
{
	draw_square(&game->minimap[0], &(t_line){0, 0, game->minimap[0].w,
		game->minimap[0].h}, 0xFF0000, true);
	draw_minimap_grid(game);
	draw_player_circle(game);
	draw_minimap_rays(game);
	circle_minimap(game);
}
