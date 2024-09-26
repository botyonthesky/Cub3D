/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_health.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:06:34 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/14 15:54:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	manage_injure(t_game *game)
{
	mlx_put_img_to_img(game->scene, game->injure, 0, 0);
	mlx_put_img_to_img(game->scene, game->congrat, 450, 450);
}
