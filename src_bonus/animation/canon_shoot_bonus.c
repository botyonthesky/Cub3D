/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canon_shoot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:48:01 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:24:06 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_canon_fire(t_game *game)
{
	assign_weapons_bool(game, CANON);
	if (game->ui_info.ammo <= 0)
		return (1);
	game->ui_info.ammo--;
	game->ui_info.full_metal--;
	game->anim.frame_canon = 0;
	assign_canon_bool(game, SHOOT);
	check_monster_shoot(game);
	check_boss_shoot(game);
	return (0);
}

void	anim_canon(t_game *game)
{
	if (game->anim.nb_anim_canon < 17000)
	{
		game->anim.nb_anim_canon++;
		return ;
	}
	game->anim.nb_anim_canon = 0;
	update_frame_canon(game);
	canon_anim(game);
	render_ui(game);
}

void	update_frame_canon(t_game *game)
{
	if (game->anim.frame_canon < 13)
		game->anim.frame_canon++;
	else
		game->anim.frame_canon = 1;
}

void	canon_anim(t_game *game)
{
	if (game->anim.frame_canon == 1)
		change_gun_sprite(game, "textures/canon/canon_idle.xpm");
	else if (game->anim.frame_canon == 2)
		change_gun_sprite(game, "textures/canon/canon_shoot2.xpm");
	else if (game->anim.frame_canon == 3)
		change_gun_sprite(game, "textures/canon/canon_shoot3.xpm");
	else if (game->anim.frame_canon == 4)
		change_gun_sprite(game, "textures/canon/canon_shoot4.xpm");
	else if (game->anim.frame_canon == 5)
		change_gun_sprite(game, "textures/canon/canon_shoot5.xpm");
	else if (game->anim.frame_canon == 6)
		change_gun_sprite(game, "textures/canon/canon_shoot6.xpm");
	else if (game->anim.frame_canon == 7)
		change_gun_sprite(game, "textures/canon/canon_shoot7.xpm");
	else if (game->anim.frame_canon == 8)
		change_gun_sprite(game, "textures/canon/canon_shoot8.xpm");
	else if (game->anim.frame_canon == 9)
		change_gun_sprite(game, "textures/canon/canon_shoot9.xpm");
	canon_anim2(game);
}

void	canon_anim2(t_game *game)
{
	if (game->anim.frame_canon == 10)
		change_gun_sprite(game, "textures/canon/canon_shoot10.xpm");
	else if (game->anim.frame_canon == 11)
		change_gun_sprite(game, "textures/canon/canon_shoot11.xpm");
	else if (game->anim.frame_canon == 12)
	{
		change_gun_sprite(game, "textures/canon/canon_shoot12.xpm");
		manage_monster(game);
		if (game->boss.health > 0)
			manage_boss(game);
	}
	else if (game->anim.frame_canon == 13)
	{
		change_gun_sprite(game, "textures/canon/canon_idle.xpm");
		assign_canon_bool(game, IDLE);
	}
}
