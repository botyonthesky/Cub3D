/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:10:42 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 09:58:02 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	anim_door_opened(t_game *game)
{
	if (game->anim.nb_anim_door_open < 4000)
	{
		game->anim.nb_anim_door_open++;
	}
	game->anim.nb_anim_door_open = 0;
	update_frame_door_opened(game);
	door_open_anim(game);
	render_ui(game);
	return (0);
}

void	update_frame_door_opened(t_game *game)
{
	if (game->anim.frame_door_open < 5)
		game->anim.frame_door_open++;
	else
		game->anim.frame_door_open = 1;
}

void	door_open_anim(t_game *game)
{
	if (game->anim.frame_door_open == 1)
		change_door_sprite(game, "textures/doors/door.xpm");
	else if (game->anim.frame_door_open == 2)
		change_door_sprite(game, "textures/doors/door2.xpm");
	else if (game->anim.frame_door_open == 3)
		change_door_sprite(game, "textures/doors/door3.xpm");
	else if (game->anim.frame_door_open == 4)
		change_door_sprite(game, "textures/doors/door4.xpm");
}
