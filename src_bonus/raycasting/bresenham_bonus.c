/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:39:51 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 08:27:51 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	bresenham_init(t_line *p, t_bresenham *b)
{
	b->dx = ft_abs(p->x2 - p->x1);
	b->dy = ft_abs(p->y2 - p->y1);
	b->points = ft_max(b->dx, b->dy);
	b->i = 0;
	if (p->x1 < p->x2)
		b->sx = 1;
	else
		b->sx = -1;
	if (p->y1 < p->y2)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
}

void	draw_point(t_img *img, t_line *p, int color)
{
	if (color == 0)
		my_mlx_pixel_put(img, p->x1, p->y1, 0x000000);
	else
		my_mlx_pixel_put(img, p->x1, p->y1, color);
}

void	bresenham_draw(t_line *p, t_bresenham *b, t_img *img, int color)
{
	while (p->x1 != p->x2 || p->y1 != p->y2)
	{
		if (p->x1 <= img->w && p->y1 <= img->h && p->x1 >= 0 && p->y1 >= 0)
			draw_point(img, p, color);
		b->i++;
		b->e2 = b->err << 1;
		if (b->e2 > -b->dy)
		{
			b->err -= b->dy;
			p->x1 += b->sx;
		}
		if (b->e2 < b->dx)
		{
			b->err += b->dx;
			p->y1 += b->sy;
		}
	}
}
