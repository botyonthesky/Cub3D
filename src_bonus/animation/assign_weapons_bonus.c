/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_weapons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:20:04 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/10 12:53:14 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	assign_pistol_bool(t_game *game, int selection)
{
	if (selection == IDLE)
	{
		game->anim.gun_idle = true;
		game->anim.gun_shoot = false;
	}
	if (selection == SHOOT)
	{
		game->anim.gun_idle = false;
		game->anim.gun_shoot = true;
	}
	game->anim.shotgun_shoot = false;
	game->anim.shotgun_idle = false;
	game->anim.canon_shoot = false;
	game->anim.canon_idle = false;
	game->anim.grenade_idle = false;
	game->anim.grenade_shoot = false;
	game->anim.expander_idle = false;
	game->anim.expander_shoot = false;
}

void	assign_shotgun_bool(t_game *game, int selection)
{
	if (selection == IDLE)
	{
		game->anim.shotgun_idle = true;
		game->anim.shotgun_shoot = false;
	}
	if (selection == SHOOT)
	{
		game->anim.shotgun_idle = false;
		game->anim.shotgun_shoot = true;
	}
	game->anim.gun_idle = false;
	game->anim.gun_shoot = false;
	game->anim.canon_shoot = false;
	game->anim.canon_idle = false;
	game->anim.grenade_idle = false;
	game->anim.grenade_shoot = false;
	game->anim.expander_idle = false;
	game->anim.expander_shoot = false;
}

void	assign_canon_bool(t_game *game, int selection)
{
	if (selection == IDLE)
	{
		game->anim.canon_idle = true;
		game->anim.canon_shoot = false;
	}
	if (selection == SHOOT)
	{
		game->anim.canon_idle = false;
		game->anim.canon_shoot = true;
	}
	game->anim.gun_idle = false;
	game->anim.gun_shoot = false;
	game->anim.shotgun_shoot = false;
	game->anim.shotgun_idle = false;
	game->anim.grenade_idle = false;
	game->anim.grenade_shoot = false;
	game->anim.expander_idle = false;
	game->anim.expander_shoot = false;
}

void	assign_grenade_bool(t_game *game, int selection)
{
	if (selection == IDLE)
	{
		game->anim.grenade_idle = true;
		game->anim.grenade_shoot = false;
	}
	if (selection == SHOOT)
	{
		game->anim.grenade_idle = false;
		game->anim.grenade_shoot = true;
	}
	game->anim.gun_idle = false;
	game->anim.gun_shoot = false;
	game->anim.shotgun_shoot = false;
	game->anim.shotgun_idle = false;
	game->anim.canon_shoot = false;
	game->anim.canon_idle = false;
	game->anim.expander_idle = false;
	game->anim.expander_shoot = false;
}

void	assign_expander_bool(t_game *game, int selection)
{
	if (selection == IDLE)
	{
		game->anim.expander_idle = true;
		game->anim.expander_shoot = false;
	}
	if (selection == SHOOT)
	{
		game->anim.expander_idle = false;
		game->anim.expander_shoot = true;
	}
	game->anim.gun_idle = false;
	game->anim.gun_shoot = false;
	game->anim.shotgun_shoot = false;
	game->anim.shotgun_idle = false;
	game->anim.canon_shoot = false;
	game->anim.canon_idle = false;
	game->anim.grenade_idle = false;
	game->anim.grenade_shoot = false;
}
