/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:33:30 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:46:43 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	change_gun_sprite(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx, game->gun.add);
	game->gun.add = mlx_xpm_file_to_image(game->mlx,
			path, &(game->gun.w), &(game->gun.h));
	game->gun.data_add = mlx_get_data_addr(game->gun.add,
			&(game->gun.bits_per_pixel), &(game->gun.line_length),
			&(game->gun.endian));
	render_ui(game);
}

void	change_door_sprite(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx, game->the_doors.add);
	game->the_doors.add = mlx_xpm_file_to_image(game->mlx,
			path, &(game->the_doors.h),
			&(game->the_doors.w));
	game->the_doors.data_add
		= mlx_get_data_addr(game->the_doors.add,
			&(game->the_doors.bits_per_pixel),
			&(game->the_doors.line_length),
			&(game->the_doors.endian));
	render_ui(game);
}

void	change_monster_sprite(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx, game->monster.add);
	game->monster.add = mlx_xpm_file_to_image(game->mlx,
			path, &game->monster.w,
			&game->monster.h);
	game->monster.data_add
		= mlx_get_data_addr(game->monster.add,
			&(game->monster.bits_per_pixel),
			&(game->monster.line_length),
			&(game->monster.endian));
	render_ui(game);
}

void	change_start_sprite(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx, game->start_anim.add);
	game->start_anim.add = mlx_xpm_file_to_image(game->mlx,
			path, &(game->start_anim.w), &(game->start_anim.h));
	game->start_anim.data_add = mlx_get_data_addr(game->start_anim.add,
			&(game->start_anim.bits_per_pixel), &(game->start_anim.line_length),
			&(game->start_anim.endian));
}
