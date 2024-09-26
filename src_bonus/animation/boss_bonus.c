/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:48 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:48:05 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_boss(t_game *game)
{
	game->boss.boss.add = mlx_xpm_file_to_image(game->mlx,
			"textures/monster/boss.xpm",
			&game->boss.boss.w, &game->boss.boss.h);
	check_xpm(game, game->boss.boss.add);
	game->boss.boss.data_add
		= mlx_get_data_addr(game->boss.boss.add,
			&game->boss.boss.bits_per_pixel,
			&game->boss.boss.line_length,
			&game->boss.boss.endian);
}

void	boss_info(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < game->map.size)
	{
		if (game->map.grid[i] == 9)
		{
			game->boss.x = (i % game->map.width) * 16 + 8;
			game->boss.y = (i / game->map.width) * 16 + 8;
		}
		i++;
	}
	game->boss.near = false;
	game->boss.alive = true;
	game->boss.health = 250;
}

void	check_for_boss(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = game->player.x;
	y = game->player.y;
	if (x >= game->boss.x - 100 && x <= game->boss.x + 100)
	{
		if (y >= game->boss.y - 100 && y <= game->boss.y + 100)
			game->boss.near = true;
		else
			game->boss.near = false;
	}
	else
		game->boss.near = false;
}

void	manage_boss(t_game *game)
{
	if (game->ui_info.shoot_on_mob == true && game->boss.near == true)
	{
		if (game->boss.health < 190 && game->boss.health >= 155)
			change_boss_sprite(game, "textures/monster/boss2.xpm");
		else if (game->boss.health < 155 && game->boss.health >= 120)
			change_boss_sprite(game, "textures/monster/boss3.xpm");
		else if (game->boss.health < 120 && game->boss.health >= 85)
			change_boss_sprite(game, "textures/monster/boss4.xpm");
		else if (game->boss.health < 85 && game->boss.health >= 50)
			change_boss_sprite(game, "textures/monster/boss5.xpm");
		else if (game->boss.health < 50 && game->boss.health >= 15)
			change_boss_sprite(game, "textures/monster/boss6.xpm");
		else if (game->boss.health < 15 && game->boss.health >= 0)
			change_boss_sprite(game, "textures/monster/boss7.xpm");
	}
	return ;
}

void	change_boss_sprite(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx, game->boss.boss.add);
	game->boss.boss.add = mlx_xpm_file_to_image(game->mlx,
			path, &game->boss.boss.w,
			&game->boss.boss.h);
	game->boss.boss.data_add
		= mlx_get_data_addr(game->boss.boss.add,
			&(game->boss.boss.bits_per_pixel),
			&(game->boss.boss.line_length),
			&(game->boss.boss.endian));
	render_ui(game);
}
