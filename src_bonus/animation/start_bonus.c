/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:56:32 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 09:07:24 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	anim_loop_start(t_game *game)
{
	if (game->anim.frame_start == 11)
	{
		change_start_sprite(game, "textures/gun/gun.xpm");
		return (1);
	}
	anim_start(game);
	return (0);
}

void	anim_start(t_game *game)
{
	if (game->anim.nb_anim_start < 15000)
	{
		game->anim.nb_anim_start++;
		return ;
	}
	game->anim.nb_anim_start = 0;
	update_frame_start(game);
	start_anim(game);
	render_ui(game);
}

void	update_frame_start(t_game *game)
{
	if (game->anim.frame_start < 13)
		game->anim.frame_start++;
	else
		game->anim.frame_start = 1;
}

void	start_anim(t_game *game)
{
	if (game->anim.frame_start == 1)
		change_start_sprite(game, "textures/start/start.xpm");
	else if (game->anim.frame_start == 2)
		change_start_sprite(game, "textures/start/start2.xpm");
	else if (game->anim.frame_start == 3)
		change_start_sprite(game, "textures/start/start2.xpm");
	else if (game->anim.frame_start == 4)
		change_start_sprite(game, "textures/start/start3.xpm");
	else if (game->anim.frame_start == 5)
		change_start_sprite(game, "textures/start/start3.xpm");
	else if (game->anim.frame_start == 6)
		change_start_sprite(game, "textures/start/start4.xpm");
	else if (game->anim.frame_start == 7)
		change_start_sprite(game, "textures/start/start4.xpm");
	start_anim2(game);
}

void	start_anim2(t_game *game)
{
	if (game->anim.frame_start == 8)
		change_start_sprite(game, "textures/start/start3.xpm");
	else if (game->anim.frame_start == 9)
		change_start_sprite(game, "textures/start/start3.xpm");
	else if (game->anim.frame_start == 10)
		change_start_sprite(game, "textures/start/start2.xpm");
	else if (game->anim.frame_start == 11)
	{
		change_start_sprite(game, "textures/start/start2.xpm");
		game->anim.start = false;
		assign_weapons_bool(game, PISTOL);
		assign_pistol_bool(game, IDLE);
	}
}
