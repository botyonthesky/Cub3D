#include "../../include/cub3d.h"

bool	check_map_texture_path(t_gc **p, int *fd, t_strtok *t)
{
	if (*fd != 0)
		return (false);
	t->o_token = ft_strtok_r(NULL, "\n\t\r ", &t->o_saveptr);
	if (t->o_token == NULL)
	{
		printf("%s", FORMAT);
		ft_gcclear(p);
		exit(0);
	}
	*fd = open(t->o_token, O_RDONLY);
	ft_memcheck(p, ft_strdup(t->o_token), FRONT, NULL);
	ft_memcheck(p, fd, FRONT, (*p)->content);
	return (true);
}

bool	check_map_texture(t_gc **p, t_map *map, t_strtok *t)
{
	bool	s;

	s = false;
	if (ft_strcmp(t->o_token, "NO") == 0)
		s = check_map_texture_path(p, &map->f_no, t);
	else if (ft_strcmp(t->o_token, "SO") == 0)
		s = check_map_texture_path(p, &map->f_so, t);
	else if (ft_strcmp(t->o_token, "WE") == 0)
		s = check_map_texture_path(p, &map->f_we, t);
	else if (ft_strcmp(t->o_token, "EA") == 0)
		s = check_map_texture_path(p, &map->f_ea, t);
	if (s == false)
		return (false);
	return (true);
}

void	textures2(t_game *game)
{
	char	*texture;

	texture = ft_gcfindone(game->p, &game->map.f_ea)->file;
	game->east.add = mlx_xpm_file_to_image(game->mlx, texture,
			&game->east.w, &game->east.h);
	game->east.data_add = mlx_get_data_addr(game->east.add,
			&game->east.bits_per_pixel, &game->east.line_length,
			&game->east.endian);
	check_xpm(game, game->east.add);
	texture = ft_gcfindone(game->p, &game->map.f_we)->file;
	game->west.add = mlx_xpm_file_to_image(game->mlx, texture,
			&game->west.w, &game->west.h);
	game->west.data_add = mlx_get_data_addr(game->west.add,
			&game->west.bits_per_pixel, &game->west.line_length,
			&game->west.endian);
	check_xpm(game, game->west.add);
}

void	textures(t_game *game)
{
	char	*texture;

	texture = ft_gcfindone(game->p, &game->map.f_no)->file;
	ft_gcdelone(game->p, &game->map.f_no);
	game->north.add = mlx_xpm_file_to_image(game->mlx, texture,
			&game->north.w, &game->north.h);
	game->north.data_add = mlx_get_data_addr(game->north.add,
			&game->north.bits_per_pixel, &game->north.line_length,
			&game->north.endian);
	check_xpm(game, game->north.add);
	texture = ft_gcfindone(game->p, &game->map.f_so)->file;
	game->south.add = mlx_xpm_file_to_image(game->mlx, texture,
			&game->south.w, &game->south.h);
	game->south.data_add = mlx_get_data_addr(game->south.add, 
			&game->south.bits_per_pixel, &game->south.line_length,
			&game->south.endian);
	check_xpm(game, game->south.add);
	textures2(game);
}
