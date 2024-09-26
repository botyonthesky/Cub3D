/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_perso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:28:58 by tmaillar          #+#    #+#             */
/*   Updated: 2024/04/25 14:04:58 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int	mlx_get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.data_add + (y * img.line_length)
			+ (x * img.bits_per_pixel / 8))));
}

void	mlx_put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.data_add + (y * img.line_length + x
				* (img.bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	mlx_put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			mlx_put_pixel_img(dst, x + i, y + j, mlx_get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
