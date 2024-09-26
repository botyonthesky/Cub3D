/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:29:18 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 09:07:20 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	anim_loop_gun_idle(t_game *game)
{
	change_gun_sprite(game, "textures/gun/gun.xpm");
	render_ui(game);
	return (0);
}

int	anim_loop_shotgun_idle(t_game *game)
{
	change_gun_sprite(game, "textures/shotgun/shotgun1.xpm");
	render_ui(game);
	return (0);
}

int	anim_loop_canon_idle(t_game *game)
{
	change_gun_sprite(game, "textures/canon/canon_idle.xpm");
	render_ui(game);
	return (0);
}

int	anim_loop_grenade_idle(t_game *game)
{
	change_gun_sprite(game, "textures/grenade/grenade_hold.xpm");
	render_ui(game);
	return (0);
}

int	anim_loop_expander_idle(t_game *game)
{
	change_gun_sprite(game, "textures/expander/expander_idle.xpm");
	render_ui(game);
	return (0);
}
