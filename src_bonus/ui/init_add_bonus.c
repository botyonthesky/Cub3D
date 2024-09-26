/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:26:35 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:30:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_add(t_game *game)
{
	game->weapons.add = mlx_xpm_file_to_image(game->mlx,
			"textures/ui_base/weapons.xpm",
			&game->weapons.w, &game->weapons.h);
	check_xpm(game, game->weapons.add);
	game->head.add = mlx_xpm_file_to_image(game->mlx,
			"textures/ui_base/head.xpm",
			&game->head.w, &game->head.h);
	check_xpm(game, game->head.add);
	game->ammo.add = mlx_xpm_file_to_image(game->mlx,
			"textures/ui_base/ammo.xpm",
			&game->ammo.w, &game->ammo.h);
	check_xpm(game, game->ammo.add);
	game->health.add = mlx_xpm_file_to_image(game->mlx,
			"textures/health/health.xpm",
			&game->health.w, &game->health.h);
	check_xpm(game, game->health.add);
	game->icon.add = mlx_xpm_file_to_image(game->mlx,
			"textures/ui_base/weapons_icon.xpm",
			&game->icon.w, &game->icon.h);
	check_xpm(game, game->icon.add);
	init_add2(game);
}

void	init_add2(t_game *game)
{
	game->paused.add = mlx_xpm_file_to_image(game->mlx,
			"textures/ui_base/paused.xpm",
			&game->paused.w, &game->paused.h);
	check_xpm(game, game->paused.add);
	game->gun.add = mlx_xpm_file_to_image(game->mlx,
			"textures/gun/gun.xpm",
			&game->gun.w, &game->gun.h);
	check_xpm(game, game->gun.add);
	game->start_anim.add = mlx_xpm_file_to_image(game->mlx,
			"textures/start/start.xpm",
			&game->start_anim.w, &game->start_anim.h);
	check_xpm(game, game->start_anim.add);
	game->aim.add = mlx_xpm_file_to_image(game->mlx,
			"textures/ui_base/aim.xpm", &game->aim.w,
			&game->aim.h);
	check_xpm(game, game->aim.add);
	init_injure_add(game);
	init_data_add(game);
	init_door(game);
	init_monster(game);
	init_boss(game);
}

void	init_injure_add(t_game *game)
{
	game->injure.add = mlx_xpm_file_to_image(game->mlx,
			"textures/health/injure.xpm", &game->injure.w,
			&game->injure.h);
	check_xpm(game, game->injure.add);
	game->congrat.add = mlx_xpm_file_to_image(game->mlx,
			"textures/congrat.xpm",
			&game->congrat.w, &game->congrat.h);
	check_xpm(game, game->congrat.add);
	game->injure.data_add = mlx_get_data_addr(game->injure.add,
			&(game->injure.bits_per_pixel),
			&(game->injure.line_length), &(game->injure.endian));
	game->congrat.data_add = mlx_get_data_addr(game->congrat.add,
			&(game->congrat.bits_per_pixel),
			&(game->congrat.line_length), &(game->congrat.endian));
}

void	init_monster(t_game *game)
{
	game->monster.add = mlx_xpm_file_to_image(game->mlx,
			"textures/monster/monster_walk.xpm",
			&game->monster.w, &game->monster.h);
	check_xpm(game, game->monster.add);
	game->monster.data_add
		= mlx_get_data_addr(game->monster.add,
			&game->monster.bits_per_pixel,
			&game->monster.line_length,
			&game->monster.endian);
}

void	init_door(t_game *game)
{
	game->the_doors.add = mlx_xpm_file_to_image(game->mlx,
			"textures/doors/door.xpm",
			&game->the_doors.w, &game->the_doors.h);
	check_xpm(game, game->the_doors.add);
	game->the_doors.data_add
		= mlx_get_data_addr(game->the_doors.add,
			&game->the_doors.bits_per_pixel,
			&game->the_doors.line_length,
			&game->the_doors.endian);
}
