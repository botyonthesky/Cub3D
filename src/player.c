#include "../include/cub3d.h"

static void	fill_player_info(t_game *game, int i)
{
	game->player.o_p = game->player.p;
	game->player.x = (i % game->map.width) * 16 + 8;
	game->player.y = (i / game->map.width) * 16 + 8;
	game->player.o_x = game->player.x;
	game->player.o_y = game->player.y;
	game->player.old_mouse_x = game->w / 2;
	game->player.mob_in_sight = 0;
	game->player.init_p = game->player.p;
	game->player.init_x = game->player.x;
	game->player.init_y = game->player.y;
	game->player.init_a = game->player.a;
}

void	player_info(t_game *game)
{
	int	i;

	i = -1;
	while (i++ < game->map.size - 1)
	{
		if (game->map.grid[i] >= 4 && game->map.grid[i] <= 7)
		{
			game->player.p = i;
			if (game->map.grid[i] == 4)
				game->player.a = game->c * 270;
			else if (game->map.grid[i] == 5)
				game->player.a = game->c * 90;
			else if (game->map.grid[i] == 6)
				game->player.a = 0;
			else if (game->map.grid[i] == 7)
				game->player.a = game->c * 180;
			game->map.grid[i] = 0;
			break ;
		}
		if (game->map.grid[i] == 2)
			game->nb_door++;
		if (game->map.grid[i] == 3)
			game->nb_monster++;
	}
	fill_player_info(game, i);
}

void	save_player_old_position(t_game *game)
{
	game->player.o_p = game->player.p;
	game->player.o_x = game->player.x;
	game->player.o_y = game->player.y;
}

void	check_player_new_position_corner(t_game *game)
{
	int	px;
	int	py;

	px = (int)(game->player.y / 16) * game->map.width
		+ ((game->player.x + 1) / 16);
	py = (int)(game->player.y + 1) / 16 * game->map.width
		+ (game->player.x / 16);
	if (game->map.grid[px] >= 1 && game->map.grid[px] < 8)
		game->player.x = game->player.o_x;
	if (game->map.grid[py] >= 1 && game->map.grid[py] < 8)
		game->player.y = game->player.o_y;
	px = (int)(game->player.y / 16) * game->map.width
		+ ((game->player.x - 1) / 16);
	py = (int)(game->player.y - 1) / 16 * game->map.width
		+ (game->player.x / 16);
	if (game->map.grid[px] >= 1 && game->map.grid[px] < 8)
		game->player.x = game->player.o_x;
	if (game->map.grid[py] >= 1 && game->map.grid[py] < 8)
		game->player.y = game->player.o_y;
}

void	check_player_new_position(t_game *game)
{
	game->player.p = (int)(game->player.y / 16) * game->map.width
		+ (game->player.x / 16);
	if (game->map.grid[game->player.p] >= 1
		&& game->map.grid[game->player.p] < 8)
	{
		game->player.y = game->player.o_y;
		game->player.x = game->player.o_x;
		game->player.p = game->player.o_p;
	}
	check_player_new_position_corner(game);
}
