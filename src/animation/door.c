#include "../../include/cub3d.h"

void	door_info(t_game *game)
{
	int	i;
	int	x;
	int	y;
	int	index;

	i = 0;
	x = 0;
	y = 0;
	index = 0;
	if (game->nb_door != 0)
	{
		while (i < game->map.size)
		{
			if (game->map.grid[i] == 2)
			{
				x = (i % game->map.width) * 16 + 8;
				y = (i / game->map.width) * 16 + 8;
				add_door_pos(game, (float)x, (float)y, index);
				game->door_pos[index].p = i;
				index++;
			}
			i++;
		}
	}
}

void	switch_doors(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_door)
	{
		if (game->door_pos[i].near == true
			&& game->door_pos[i].close == true)
		{
			assign_door_bool(game, i, OPEN);
			game->map.grid[game->door_pos[i].p] = 8;
		}
		else if (game->door_pos[i].near == true
			&& game->door_pos[i].open == true)
		{
			assign_door_bool(game, i, CLOSE);
			change_door_sprite(game, "textures/doors/door.xpm");
			game->map.grid[game->door_pos[i].p] = 2;
			break ;
		}
		i++;
	}
}

void	check_for_door(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = game->player.x;
	y = game->player.y;
	while (i < game->nb_door)
	{
		if (x >= game->door_pos[i].x - 10 && x <= game->door_pos[i].x + 10)
		{
			if (y >= game->door_pos[i].y - 30 && y <= game->door_pos[i].y + 30)
			{
				game->door_pos[i].near = true;
			}
			else
				game->door_pos[i].near = false;
		}
		else
			game->door_pos[i].near = false;
		i++;
	}
}

int	open_door(t_game *game)
{
	anim_loop_door_opened(game);
	return (0);
}

int	close_door(t_game *game)
{
	anim_loop_door_closed(game);
	return (0);
}
