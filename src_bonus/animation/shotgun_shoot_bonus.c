/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shotgun_shoot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:28:07 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:25:52 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_shotgun_fire(t_game *game)
{
	assign_weapons_bool(game, SHOTGUN);
	if (game->ui_info.ammo <= 0)
		return (1);
	game->ui_info.ammo -= 2;
	game->ui_info.shotg -= 2;
	game->anim.frame_shotgun = 0;
	assign_shotgun_bool(game, SHOOT);
	check_monster_shoot(game);
	check_boss_shoot(game);
	return (0);
}

void	anim_shotgun(t_game *game)
{
	if (game->anim.nb_anim_shotgun < 5000)
	{
		game->anim.nb_anim_shotgun++;
		return ;
	}
	game->anim.nb_anim_shotgun = 0;
	update_frame_shotgun(game);
	shotgun_anim(game);
	render_ui(game);
}

void	update_frame_shotgun(t_game *game)
{
	if (game->anim.frame_shotgun < 16)
		game->anim.frame_shotgun++;
	else
		game->anim.frame_shotgun = 1;
}

void	shotgun_anim(t_game *game)
{
	if (game->anim.frame_shotgun == 1)
		change_gun_sprite(game, "textures/shotgun/shotgun1.xpm");
	else if (game->anim.frame_shotgun == 2)
		change_gun_sprite(game, "textures/shotgun/shotgun2.xpm");
	else if (game->anim.frame_shotgun == 3)
		change_gun_sprite(game, "textures/shotgun/shotgun3.xpm");
	else if (game->anim.frame_shotgun == 4)
		change_gun_sprite(game, "textures/shotgun/shotgun4.xpm");
	else if (game->anim.frame_shotgun == 5)
		change_gun_sprite(game, "textures/shotgun/shotgun5.xpm");
	else if (game->anim.frame_shotgun == 6)
		change_gun_sprite(game, "textures/shotgun/shotgun6.xpm");
	else if (game->anim.frame_shotgun == 7)
		change_gun_sprite(game, "textures/shotgun/shotgun7.xpm");
	else if (game->anim.frame_shotgun == 8)
		change_gun_sprite(game, "textures/shotgun/shotgun8.xpm");
	else if (game->anim.frame_shotgun == 9)
		change_gun_sprite(game, "textures/shotgun/shotgun9.xpm");
	manage_monster(game);
	if (game->boss.health > 0)
		manage_boss(game);
	shotgun_anim_2(game);
}

void	shotgun_anim_2(t_game *game)
{
	if (game->anim.frame_shotgun == 10)
		change_gun_sprite(game, "textures/shotgun/shotgun10.xpm");
	else if (game->anim.frame_shotgun == 11)
		change_gun_sprite(game, "textures/shotgun/shotgun11.xpm");
	else if (game->anim.frame_shotgun == 12)
		change_gun_sprite(game, "textures/shotgun/shotgun12.xpm");
	else if (game->anim.frame_shotgun == 13)
		change_gun_sprite(game, "textures/shotgun/shotgun13.xpm");
	else if (game->anim.frame_shotgun == 14)
		change_gun_sprite(game, "textures/shotgun/shotgun14.xpm");
	else if (game->anim.frame_shotgun == 15)
	{
		change_gun_sprite(game, "textures/shotgun/shotgun1.xpm");
		assign_shotgun_bool(game, IDLE);
	}
	return ;
}
