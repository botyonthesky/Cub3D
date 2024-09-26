/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:00:20 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 07:47:02 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_map_spawn(t_map *map)
{
	if (map->spawn_set == false)
	{
		printf("%s", FORMAT);
		return (false);
	}
	return (true);
}

bool	check_map_grid(t_map *map, char *line)
{
	static bool	map_started = false;
	int			len;

	if (map_started && *line == '\n')
		return (false);
	len = ft_strlen(line) - 1;
	if (len > map->width)
		map->width = len;
	while (--len >= 0)
	{
		map_started = true;
		if (ft_strchr("NSEW", line[len]))
		{
			if (map->spawn_set == true)
				return (false);
			map->spawn_set = true;
		}
		else if (ft_strchr("01 GMB", line[len]) == NULL)
			return (false);
	}
	if (map_started)
		map->height++;
	return (true);
}

bool	check_map_content(t_gc **p, t_map *map, char *line)
{
	t_strtok	t;

	ft_memset(&t, 0, sizeof(t));
	t.str = line;
	t.o_token = ft_strtok_r(t.str, "\n\t\r ", &t.o_saveptr);
	while (t.o_token != NULL)
	{
		if (!check_map_texture(p, map, &t) && !check_map_colors(map, &t))
			return (false);
		t.o_token = ft_strtok_r(NULL, "\n\t\r ", &t.o_saveptr);
		if (t.o_token != NULL)
			return (false);
	}
	if (map->grid == NULL)
		return (true);
	return (false);
}

bool	check_map(t_gc **p, t_map *map, char *path_to_map)
{
	char	*line;
	int		i;

	map->map = open(path_to_map, O_RDONLY);
	map->spawn_set = false;
	ft_memcheck(p, &map->map, FRONT, path_to_map);
	i = 0;
	while (1)
	{
		line = gnl_check(p, get_next_line(map->map, 0));
		if (line == NULL)
			break ;
		ft_memcheck(p, line, FRONT, NULL);
		if ((fill_grid(map, i) || !check_map_content(p, map, line))
			&& (fill_grid(map, i) && !check_map_grid(map, line)))
		{
			printf("%s", FORMAT);
			return (false);
		}
		ft_gcdelone(p, line);
		i++;
	}
	return (check_map_spawn(map));
}
