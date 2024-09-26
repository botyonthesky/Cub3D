#include "../../include/cub3d.h"

int	manage_pause(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	mlx_put_image_to_window(game->mlx, game->win, game->paused.add, 0, 0);
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-35-*-*-*-*-*-*-*");
	mlx_string_put(game->mlx, game->win, x - 90, y - 80, -1, "Return game");
	mlx_string_put(game->mlx, game->win, x - 99, y, -1, "Restart game");
	mlx_string_put(game->mlx, game->win, x - 70, y + 80, -1, "Quit game");
	select_line(game);
	mlx_hook(game->win, 2, 1L << 0, &handle_key, game);
	return (1);
}

void	select_line(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-55-*-*-*-*-*-*-*");
	if (game->ui_info.on_return == true)
	{
		mlx_string_put(game->mlx, game->win, x - 155, y - 74, 0xFF0000, "->");
		mlx_string_put(game->mlx, game->win, x + 110, y - 74, 0xFF0000, "<-");
	}
	else if (game->ui_info.on_restart == true)
	{
		mlx_string_put(game->mlx, game->win, x - 165, y + 7, 0xFF0000, "->");
		mlx_string_put(game->mlx, game->win, x + 118, y + 7, 0xFF0000, "<-");
	}
	else if (game->ui_info.on_quit == true)
	{
		mlx_string_put(game->mlx, game->win, x - 135, y + 87, 0xFF0000, "->");
		mlx_string_put(game->mlx, game->win, x + 93, y + 87, 0xFF0000, "<-");
	}
}

int	handle_key(int key, t_game *game)
{
	if (key == XK_Return)
	{
		game->ui_info.paused = false;
		if (game->ui_info.on_return == true)
			render_general(game);
		if (game->ui_info.on_restart == true)
		{
			init_ui(game);
			init_restart(game);
			game->player.x = game->player.init_x;
			game->player.y = game->player.init_y;
			game->player.p = game->player.init_p;
			game->player.a = game->player.init_a;
			render_general(game);
		}
		if (game->ui_info.on_quit == true)
			destroy_win(game);
	}
	if (key == XK_Down)
		switch_return(game, 1);
	if (key == XK_Up)
		switch_return(game, 2);
	if (key == XK_p)
		render_general(game);
	return (0);
}

void	init_restart(t_game *game)
{
	mlx_destroy_image(game->mlx, game->the_doors.add);
	init_door(game);
	check_for_door(game);
	mlx_destroy_image(game->mlx, game->monster.add);
	init_monster(game);
	mlx_destroy_image(game->mlx, game->boss.boss.add);
	init_boss(game);
}
