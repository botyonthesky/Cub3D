/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:56:57 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 07:48:28 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

struct	s_scene
{
	int		i;
	int		height;
	int		start;
	int		end;
	float	diff_y;
	float	y;
	float	texture_y;
	float	texture_x;
	int		color;
	t_img	texture;
};

static t_img	pick_texture(t_game *game, int i)
{
	if (game->map.rays_o[i] == 0)
		return (game->north);
	else if (game->map.rays_o[i] == 1)
		return (game->south);
	else if (game->map.rays_o[i] == 2)
		return (game->east);
	else if (game->map.rays_o[i] == 3)
		return (game->west);
	else if (game->map.rays_o[i] == 4 || game->map.rays_o[i] == 11)
		return (game->the_doors);
	else if (game->map.rays_o[i] == 5 || game->map.rays_o[i] == 11)
		return (game->the_doors);
	else if (game->map.rays_o[i] == 6)
		return (game->monster);
	else if (game->map.rays_o[i] == 12)
		return (game->boss.boss);
	return (game->north);
}

static void	draw_ceiling_and_floor(t_game *game, struct s_scene *s)
{
	if (s->start > 0)
		draw_line(&game->scene, &(t_line){s->i, 0, s->i, s->start},
			game->map.c_c.c);
	if (s->end < game->h)
		draw_line(&game->scene, &(t_line){s->i, s->end, s->i, game->h},
			game->map.f_c.c);
}

static void	draw_texture(t_game *game, struct s_scene *s)
{
	while (s->y < s->diff_y)
	{
		if (s->start + s->y > game->h)
			break ;
		s->texture_y = (s->texture.h * s->y) / s->diff_y;
		s->texture_x = game->map.rays_x[s->i] * s->texture.w / 16;
		s->color = mlx_get_pixel_color(&s->texture, s->texture_x, s->texture_y);
		my_mlx_pixel_put(&game->scene, s->i, s->start + s->y, s->color);
		s->y++;
	}
}

void	draw_scene(t_game *game)
{
	struct s_scene	s;

	s.i = 0;
	while (++s.i < game->w)
	{
		if (game->map.rays[s.i] == 0)
			s.height = 0;
		else
			s.height = game->h / game->map.rays[s.i];
		s.start = -s.height + game->h / 2;
		s.end = s.height + game->h / 2;
		s.diff_y = s.end - s.start;
		draw_ceiling_and_floor(game, &s);
		s.y = 0;
		if (s.start < 0)
			s.y = abs(0 - s.start);
		s.texture = pick_texture(game, s.i);
		draw_texture(game, &s);
	}
}
