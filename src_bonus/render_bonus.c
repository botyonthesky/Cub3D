/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:40:41 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/15 14:54:15 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	render_ui(t_game *game)
{
	if (game->ui_info.paused == true)
		return (manage_pause(game));
	else
	{
		mlx_clear_window(game->mlx, game->win);
		draw_minimap(game);
		draw_scene(game);
		manage_img_to_img(game);
		mlx_put_image_to_window(game->mlx, game->win, game->scene.add, 0, 0);
		put_ui_image(game);
		if (game->boss.health <= 0)
			manage_injure(game);
		put_ui_info(game);
		manage_ui_weapons(game);
		print_coordinates(game);
		mlx_do_sync(game->mlx);
		return (0);
	}
}

void	print_coordinates(t_game *game)
{
	ft_memset(game->map.s, 0, 30);
	ft_strlcat(game->map.s, "x: ", 30);
	ft_strlcat(game->map.s, ft_itoa(game->player.x), 30);
	ft_strlcat(game->map.s, " y: ", 30);
	ft_strlcat(game->map.s, ft_itoa(game->player.y), 30);
	ft_strlcat(game->map.s, " a: ", 30);
	ft_strlcat(game->map.s, ft_itoa(game->player.a / game->c), 30);
}

int	render_general(t_game *game)
{
	render_ui(game);
	mlx_hook(game->win, 2, 1L << 0, &handle_keyboard, game);
	mlx_hook(game->win, 6, 1L << 6, &handle_mouse, game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

int	my_loop_hook(t_game *game)
{
	if (game->anim.start == true)
		anim_loop_start(game);
	if (game->anim.gun_idle == true && game->anim.start == false)
		anim_loop_gun_idle(game);
	else if (game->anim.shotgun_idle == true)
		anim_loop_shotgun_idle(game);
	else if (game->anim.canon_idle == true)
		anim_loop_canon_idle(game);
	else if (game->anim.grenade_idle == true)
		anim_loop_grenade_idle(game);
	else if (game->anim.expander_idle == true)
		anim_loop_expander_idle(game);
	if (game->anim.gun_shoot == true)
		anim_gun_shoot(game);
	else if (game->anim.shotgun_shoot == true)
		anim_shotgun(game);
	else if (game->anim.canon_shoot == true)
		anim_canon(game);
	else if (game->anim.grenade_shoot == true)
		anim_grenade(game);
	else if (game->anim.expander_shoot == true)
		anim_expander(game);
	manage_door(game);
	return (0);
}
