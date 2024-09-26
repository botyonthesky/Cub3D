/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:20:50 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 09:06:57 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	anim_door_closed(t_game *game)
{
	if (game->anim.nb_anim_door_close < 5000)
	{
		game->anim.nb_anim_door_close++;
	}
	game->anim.nb_anim_door_close = 0;
	update_frame_door_closed(game);
	door_closed_anim(game);
	render_ui(game);
}

void	update_frame_door_closed(t_game *game)
{
	if (game->anim.frame_door_close < 5)
		game->anim.frame_door_close++;
	else
		game->anim.frame_door_close = 1;
}

void	door_closed_anim(t_game *game)
{
	if (game->anim.frame_door_close == 1)
		change_door_sprite(game, "textures/doors/door4.xpm");
	else if (game->anim.frame_door_close == 2)
		change_door_sprite(game, "textures/doors/door3.xpm");
	else if (game->anim.frame_door_close == 3)
		change_door_sprite(game, "textures/doors/door2.xpm");
	else if (game->anim.frame_door_close == 4)
		change_door_sprite(game, "textures/doors/door.xpm");
	return ;
}
