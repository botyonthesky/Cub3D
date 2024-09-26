#include "../../include/cub3d.h"

char	*gnl_check(t_gc **p, char *line)
{
	if (errno)
	{
		perror("Memory allocation failed");
		ft_gcclear(p);
		exit (EXIT_FAILURE);
	}
	return (line);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		if (i % map->width == 0 && i != 0)
			printf("\n");
		printf("%d ", map->grid[i]);
		i++;
	}
	printf("\n");
}

void	check_args(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strstr(av[1], ".cub") != 0)
			if (*(ft_strstr(av[1], ".cub") + 4) == '\0')
				return ;
	}
	printf("%s", USAGE);
	exit(EXIT_SUCCESS);
}

void	replace_values_map_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		if (map->grid[i] == '0')
			map->grid[i] = 0;
		if (map->grid[i] == ' ' || map->grid[i] == '1')
			map->grid[i] = 1;
		else if (map->grid[i] == 'G')
			map->grid[i] = 2;
		else if (map->grid[i] == 'M')
			map->grid[i] = 3;
		else if (map->grid[i] == 'N')
			map->grid[i] = 4;
		else if (map->grid[i] == 'S')
			map->grid[i] = 5;
		else if (map->grid[i] == 'E')
			map->grid[i] = 6;
		else if (map->grid[i] == 'W')
			map->grid[i] = 7;
		else if (map->grid[i] == 'B')
			map->grid[i] = 9;
		i++;
	}
}
