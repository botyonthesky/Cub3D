/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:59:07 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 14:12:49 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	floodfill_line(int *grid, int max, int *min, int inc)
{
	while (*min != max)
	{
		if (grid[*min] != 1)
			return (false);
		*min = *min + inc;
	}
	if (grid[*min] != 1)
		return (false);
	return (true);
}

bool	floodfill(t_map *map)
{
	int	i;

	i = 0;
	if (floodfill_line(map->grid, map->width, &i, 1) == false)
		return (false);
	i--;
	if (floodfill_line(map->grid, map->size - 1, &i, map->width) == false)
		return (false);
	if (floodfill_line(map->grid, map->size - map->width, &i, -1) == false)
		return (false);
	if (floodfill_line(map->grid, 0, &i, -map->width) == false)
		return (false);
	return (true);
}

bool	fill_grid(t_map *map, int i)
{
	if (map->c_c.c == -1)
		return (false);
	if (map->f_c.c == -1)
		return (false);
	if (map->f_no == 0)
		return (false);
	if (map->f_so == 0)
		return (false);
	if (map->f_we == 0)
		return (false);
	if (map->f_ea == 0)
		return (false);
	if (map->size == 0)
		map->size = i;
	return (true);
}

bool	fill_map_grid(t_gc **p, t_map *map)
{
	int		i;
	char	*line;

	line = fill_map_grid_init(p, map);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
			*map->grid++ = line[i++];
		while (i++ < map->width)
			*map->grid++ = 32;
		free(line);
		line = gnl_check(p, get_next_line(map->map, 0));
	}
	map->grid -= map->size;
	replace_values_map_grid(map);
	if (floodfill(map) == false)
	{
		printf("%s", FORMAT);
		return (false);
	}
	print_map(map);
	return (true);
}

char	*fill_map_grid_init(t_gc **p, t_map *map)
{
	int		i;
	int		j;
	char	*line;

	reopen(p, &map->map);
	j = map->size;
	map->size = map->width * map->height;
	map->grid = malloc(sizeof(*map->grid) * map->size);
	ft_memcheck(p, map->grid, FRONT, NULL);
	ft_memset(map->grid, 0, map->size);
	i = 0;
	while (i++ != j)
	{
		line = gnl_check(p, get_next_line(map->map, 0));
		free(line);
	}
	line = gnl_check(p, get_next_line(map->map, 0));
	while (line != NULL && *line == '\n')
	{
		free(line);
		line = gnl_check(p, get_next_line(map->map, 0));
	}
	return (line);
}
