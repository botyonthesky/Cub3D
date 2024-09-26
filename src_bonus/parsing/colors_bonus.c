/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:03:15 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 14:08:47 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	assign_map_colors(t_color *color, t_strtok *t)
{
	char	*endptr;

	t->i_token = ft_strtok_r(t->o_token, ",", &t->i_saveptr);
	if (t->i_token == NULL || color->c != -1)
		return (false);
	color->r = ft_strtoi(t->i_token, &endptr);
	if (color->r < 0 || color->r > 255 || *endptr != '\0')
		return (false);
	t->i_token = ft_strtok_r(NULL, ",", &t->i_saveptr);
	if (t->i_token == NULL)
		return (false);
	color->g = ft_strtoi(t->i_token, &endptr);
	if (color->g < 0 || color->g > 255 || *endptr != '\0')
		return (false);
	t->i_token = ft_strtok_r(NULL, ",", &t->i_saveptr);
	if (t->i_token == NULL)
		return (false);
	color->b = ft_strtoi(t->i_token, &endptr);
	if (color->b < 0 || color->b > 255 || *endptr != '\0')
		return (false);
	color->a = 0;
	color->c = ft_rgb_to_hex(*color);
	if (t->i_saveptr != NULL)
		return (false);
	return (true);
}

bool	check_map_colors(t_map *map, t_strtok *t)
{
	bool	s;

	s = false;
	if (t->o_token == NULL)
		return (false);
	if (ft_strcmp(t->o_token, "F") == 0)
		s = true;
	else if (ft_strcmp(t->o_token, "C") == 0)
		s = true;
	if (s == false)
		return (false);
	t->o_token = ft_strtok_r(NULL, "\n\t\r ", &t->o_saveptr);
	if (t->o_token == NULL)
		return (false);
	if (count_tokens(t->o_token, ",") > 3)
		return (false);
	if (!ft_strcmp(t->str, "F") && assign_map_colors(&map->f_c, t) == false)
		return (false);
	if (!ft_strcmp(t->str, "C") && assign_map_colors(&map->c_c, t) == false)
		return (false);
	return (true);
}
