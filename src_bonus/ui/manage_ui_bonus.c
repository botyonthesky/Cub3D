/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:13:53 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/15 07:38:48 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	manage_img_to_img(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	mlx_put_img_to_img(game->scene, game->aim, x - 10, y);
	if (game->anim.start == true)
		mlx_put_img_to_img(game->scene, game->start_anim, x - 105, y + 58);
	else if (game->ui_info.pistol == true)
		mlx_put_img_to_img(game->scene, game->gun, x + 40, y + 160);
	else if (game->ui_info.shotgun == true)
		mlx_put_img_to_img(game->scene, game->gun, x - 10, y + 114);
	else if (game->ui_info.canon == true)
		mlx_put_img_to_img(game->scene, game->gun, x - 60, y + 4);
	else if (game->ui_info.grenade == true)
		mlx_put_img_to_img(game->scene, game->gun, x - 105, y + 48);
	else if (game->ui_info.expander == true)
		mlx_put_img_to_img(game->scene, game->gun, x - 30, y + 44);
	mlx_put_img_to_img(game->scene, game->minimap[1], 50, 50);
}

void	manage_fire(t_game *game)
{
	if (game->ui_info.pistol == true)
		manage_gun_fire(game);
	else if (game->ui_info.shotgun == true)
		manage_shotgun_fire(game);
	else if (game->ui_info.canon == true)
		manage_canon_fire(game);
	else if (game->ui_info.grenade == true)
		manage_grenade_fire(game);
	else if (game->ui_info.expander == true)
		manage_expander_fire(game);
}
