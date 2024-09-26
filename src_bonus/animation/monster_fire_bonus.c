/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_fire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:31:10 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/15 09:06:23 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_monster_shoot(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_monster)
	{
		if (game->monster_pos[i].near == true)
		{
			if (game->player.mob_in_sight == 1)
			{
				game->ui_info.shoot_on_mob = true;
				if (game->monster_pos[i].health > 0)
					manage_monster_health(game, i);
			}
		}
		i++;
	}
}

void	check_boss_shoot(t_game *game)
{
	if (game->boss.near == true)
	{
		if (game->player.mob_in_sight == 1)
		{
			game->ui_info.shoot_on_mob = true;
			if (game->boss.health > 0)
				manage_boss_health(game);
		}
	}
}

void	manage_monster_health(t_game *game, int i)
{
	if (game->ui_info.pistol == true)
		game->monster_pos[i].health -= 5;
	if (game->ui_info.shotgun == true)
		game->monster_pos[i].health -= 14;
	if (game->ui_info.canon == true)
		game->monster_pos[i].health -= 48;
	if (game->ui_info.grenade == true)
		game->monster_pos[i].health -= 32;
	if (game->ui_info.expander == true)
		game->monster_pos[i].health -= 100;
}

void	manage_boss_health(t_game *game)
{
	if (game->ui_info.pistol == true)
		game->boss.health -= 5;
	if (game->ui_info.shotgun == true)
		game->boss.health -= 14;
	if (game->ui_info.canon == true)
		game->boss.health -= 48;
	if (game->ui_info.grenade == true)
		game->boss.health -= 32;
	if (game->ui_info.expander == true)
		game->boss.health -= 100;
}
