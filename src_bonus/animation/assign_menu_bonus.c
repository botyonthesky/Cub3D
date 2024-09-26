/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:22:01 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 06:48:25 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	assign_pause_bool(t_game *game, int selection)
{
	if (selection == RETURN)
	{
		game->ui_info.on_return = true;
		game->ui_info.on_restart = false;
		game->ui_info.on_quit = false;
	}
	if (selection == RESTART)
	{
		game->ui_info.on_return = false;
		game->ui_info.on_restart = true;
		game->ui_info.on_quit = false;
	}
	if (selection == QUIT)
	{
		game->ui_info.on_return = false;
		game->ui_info.on_restart = false;
		game->ui_info.on_quit = true;
	}
	return (1);
}

int	assign_menu_bool(t_game *game, int selection)
{
	if (selection == START)
	{
		game->ui_info.on_start = true;
		game->ui_info.on_exit = false;
	}
	else if (selection == EXIT)
	{
		game->ui_info.on_start = false;
		game->ui_info.on_exit = true;
	}
	return (1);
}

void	assign_door_bool(t_game *game, int i, int selection)
{
	if (selection == OPEN)
	{
		if (game->door_pos[i].close == true)
		{
			game->door_pos[i].close = false;
			game->door_pos[i].open = true;
		}
	}
	else if (selection == CLOSE)
	{
		if (game->door_pos[i].open == true)
		{
			game->door_pos[i].open = false;
			game->door_pos[i].close = true;
		}
	}
}
