/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:41:56 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/10 12:59:09 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_an_horizontal_wall(t_game *game, float x, float y)
{
	int	p;

	if (game->player.a > game->c * 180)
		y -= 16;
	p = (int)((y / 16) * game->map.width + (x / 16));
	if (p < 0 || p >= game->map.size)
		return (1);
	return (game->map.grid[p]);
}

int	is_a_vertical_wall(t_game *game, float x, float y)
{
	int	p;

	if (game->player.a > game->c * 90 && game->player.a < game->c * 270)
		x -= 16;
	p = ((int)(y / 16)) * game->map.width + (x / 16);
	if (p < 0 || p > game->map.size)
		return (1);
	return (game->map.grid[p]);
}
