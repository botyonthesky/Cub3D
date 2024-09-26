/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:28:21 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:55:56 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_ui(t_game *game)
{
	game->ui_info.health = 100;
	game->ui_info.ammo = 99;
	game->ui_info.bull = game->ui_info.ammo;
	game->ui_info.bull_max = 200;
	game->ui_info.shotg = 30;
	game->ui_info.shotg_max = 50;
	game->ui_info.full_metal = 10;
	game->ui_info.fm_max = 20;
	game->ui_info.grenades = 18;
	game->ui_info.grenade_max = 20;
	game->ui_info.expanders = 15;
	game->ui_info.expander_max = 10;
	game->ui_info.pistol = false;
	game->ui_info.shotgun = false;
	game->ui_info.canon = false;
	game->ui_info.paused = false;
	game->ui_info.grenade = false;
	game->ui_info.expander = false;
	game->ui_info.on_return = true;
	game->ui_info.on_restart = false;
	game->ui_info.on_exit = false;
	game->ui_info.shoot_on_mob = false;
	game->boss.health = 250;
	init_anim(game);
}

void	init_anim(t_game *game)
{
	game->anim.nb_anim_gun_shoot = 0;
	game->anim.nb_anim_shotgun = 0;
	game->anim.nb_anim_canon = 0;
	game->anim.nb_anim_grenade = 0;
	game->anim.nb_anim_expander = 0;
	game->anim.nb_anim_door_close = 0;
	game->anim.nb_anim_door_open = 0;
	game->anim.nb_anim_monster_walk = 0;
	game->anim.nb_anim_monster_fire = 0;
	game->anim.nb_anim_start = 0;
	game->anim.start = true;
	game->anim.gun_idle = false;
	game->anim.gun_shoot = false;
	game->anim.shotgun_shoot = false;
	game->anim.shotgun_idle = false;
	game->anim.canon_shoot = false;
	game->anim.canon_idle = false;
	game->anim.grenade_idle = false;
	game->anim.grenade_shoot = false;
	game->anim.expander_idle = false;
	game->anim.expander_shoot = false;
	init_frame(game);
}

void	init_frame(t_game *game)
{
	game->anim.frame_gun_shoot = 0;
	game->anim.frame_shotgun = 0;
	game->anim.frame_canon = 0;
	game->anim.frame_grenade = 0;
	game->anim.frame_expander = 0;
	game->anim.frame_start = 0;
	game->anim.frame_door_close = 0;
	game->anim.frame_door_open = 0;
	game->anim.frame_monster_fire = 0;
	game->anim.frame_monster_walk = 0;
	game->anim.still_shoot = false;
}

void	init_data_add(t_game *game)
{
	game->gun.data_add = mlx_get_data_addr(game->gun.add,
			&(game->gun.bits_per_pixel), &(game->gun.line_length),
			&(game->gun.endian));
	game->start_anim.data_add = mlx_get_data_addr(game->start_anim.add,
			&(game->start_anim.bits_per_pixel), &(game->start_anim.line_length),
			&(game->start_anim.endian));
	game->aim.data_add = mlx_get_data_addr(game->aim.add,
			&(game->aim.bits_per_pixel), &(game->aim.line_length),
			&(game->aim.endian));
}

void	init_add_tab(t_game *game)
{
	game->add_tab = ft_calloc(22, sizeof(void *));
	ft_memcheck(game->p, game->add_tab, FRONT, NULL);
}
