/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:03:29 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/15 07:27:14 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	anim_loop_door_opened(t_game *game)
{
	if (game->anim.frame_door_open == 4)
	{
		change_door_sprite(game, "textures/doors/door4.xpm");
		return (1);
	}
	anim_door_opened(game);
	return (0);
}

int	anim_loop_door_closed(t_game *game)
{
	if (game->anim.frame_door_close == 4)
	{
		change_door_sprite(game, "textures/doors/door.xpm");
		return (1);
	}
	anim_door_closed(game);
	return (0);
}

void	manage_door(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_door)
	{
		if (game->door_pos[i].near == true && game->door_pos[i].open == true)
		{
			open_door(game);
			game->map.grid[game->door_pos[i].p] = 8;
			game->door_pos[i].first = true;
		}
		if (game->door_pos[i].near == false && game->door_pos[i].open == true
			&& game->door_pos[i].first == true)
		{
			change_door_sprite(game, "textures/doors/door.xpm");
			game->map.grid[game->door_pos[i].p] = 2;
			game->anim.frame_door_close = 0;
			game->anim.frame_door_open = 0;
			assign_door_bool(game, i, CLOSE);
			game->door_pos[i].first = false;
		}
		i++;
	}
	game->anim.nb_anim_door_open = 0;
	game->anim.nb_anim_door_close = 0;
}

void	add_door_pos(t_game *game, float pos_x, float pos_y, int index)
{
	if (index >= 0 && index < game->nb_door)
	{
		game->door_pos[index].x = pos_x;
		game->door_pos[index].y = pos_y;
		game->door_pos[index].near = false;
		game->door_pos[index].open = false;
		game->door_pos[index].close = true;
		game->door_pos[index].first = false;
	}
}
