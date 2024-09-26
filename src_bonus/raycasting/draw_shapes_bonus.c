/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:38:54 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/14 15:56:47 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_circle_points(t_img *img, t_line *p, int color)
{
	my_mlx_pixel_put(img, p->x1 + p->x2, p->y1 + p->y2, color);
	my_mlx_pixel_put(img, p->x1 - p->x2, p->y1 + p->y2, color);
	my_mlx_pixel_put(img, p->x1 + p->x2, p->y1 - p->y2, color);
	my_mlx_pixel_put(img, p->x1 - p->x2, p->y1 - p->y2, color);
	my_mlx_pixel_put(img, p->x1 + p->y2, p->y1 + p->x2, color);
	my_mlx_pixel_put(img, p->x1 - p->y2, p->y1 + p->x2, color);
	my_mlx_pixel_put(img, p->x1 + p->y2, p->y1 - p->x2, color);
	my_mlx_pixel_put(img, p->x1 - p->y2, p->y1 - p->x2, color);
}

void	draw_circle(t_img *img, t_circle *p, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = p->r;
	d = 3 - 2 * p->r;
	draw_circle_points(img, &(t_line){p->x, p->y, x, y}, color);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		draw_circle_points(img, &(t_line){p->x, p->y, x, y}, color);
	}
}

void	draw_line(t_img *img, t_line *p, int color)
{
	t_bresenham	b;

	bresenham_init(p, &b);
	bresenham_draw(p, &b, img, color);
}

void	draw_square(t_img *img, t_line *p, int color, bool inner)
{
	draw_line(img, &(t_line){p->x1, p->y1, p->x2, p->y1}, color);
	draw_line(img, &(t_line){p->x1, p->y1, p->x1, p->y2}, color);
	draw_line(img, &(t_line){p->x2, p->y2, p->x1, p->y2}, color);
	draw_line(img, &(t_line){p->x2, p->y2, p->x2, p->y1}, color);
	if (inner)
	{
		while (p->x1 != p->x2)
		{
			draw_line(img, &(t_line){p->x1, p->y1, p->x1, p->y2}, color);
			p->x1++;
		}
	}
}

void	draw_outer_circle(t_img *img, t_circle *p, int fill_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->h)
	{
		j = 0;
		while (j < img->w)
		{
			if (!is_inside_circle(&(t_circle){j, i, p->x, p->y, p->r}))
				my_mlx_pixel_put(img, j, i, fill_color);
			j++;
		}
		i++;
	}
}
