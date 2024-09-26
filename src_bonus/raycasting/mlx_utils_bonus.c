/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:42:49 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/07 15:14:56 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > img->w || y > img->h || x < 0 || y < 0)
		return ;
	dst = img->data_add + (y * img->line_length + x * \
		(img->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

int	mlx_get_pixel_color(t_img *img, int x, int y)
{
	if (x > img->w || y > img->h || x < 0 || y < 0)
		return (0);
	return (*(int *)(img->data_add + (y * img->line_length + x
			* (img->bits_per_pixel >> 3))));
}
