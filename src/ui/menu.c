#include "../../include/cub3d.h"

void	start_menu(t_gc **p, t_game *game)
{
	game->mlx = mlx_init();
	ft_memcheck(p, game->mlx, FRONT, NULL);
	init_add_tab(game);
	mlx_get_screen_size(game->mlx, &(game->w), &(game->h));
	game->c = game->w / (FOV / 2);
	player_info(game);
	door_info(game);
	monsters_info(game);
	boss_info(game);
	trig_tables(game->p, game);
	game->map.rays = malloc(sizeof(game->map.rays) * game->w);
	ft_memcheck(game->p, game->map.rays, FRONT, NULL);
	game->map.rays_o = malloc(sizeof(game->map.rays_o) * game->w);
	ft_memcheck(game->p, game->map.rays_o, FRONT, NULL);
	game->map.rays_x = malloc(sizeof(game->map.rays_x) * game->w);
	ft_memcheck(game->p, game->map.rays_x, FRONT, NULL);
	trig_tables(game->p, game);
	game->win = mlx_new_window(game->mlx, game->w, game->h, "cub3D");
	init_menu(game);
	mlx_expose_hook(game->win, &menu, game);
	mlx_hook(game->win, 2, 1L << 0, &handle_menu, game);
	mlx_hook(game->win, 17, 0, &destroy_win, game);
	mlx_loop(game->mlx);
}

int	menu(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	if (game->start == false)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->menu.add, 0, 0);
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-35-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x - 60, y + 210, -1, "New Game");
		mlx_string_put(game->mlx, game->win, x - 30, y + 290, -1, "Exit");
		select_menu(game);
	}
	return (0);
}

void	select_menu(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	if (game->ui_info.on_start == true)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-55-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x - 130, y + 217, 0xFF0000, "->");
		mlx_string_put(game->mlx, game->win, x + 90, y + 217, 0xFF0000, "<-");
	}
	else if (game->ui_info.on_exit == true)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-55-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x - 95, y + 296, 0xFF0000, "->");
		mlx_string_put(game->mlx, game->win, x + 48, y + 296, 0xFF0000, "<-");
	}
}

int	handle_menu(int key, t_game *game)
{
	if (key == XK_Escape)
		destroy_win(game);
	else if (key == XK_Return)
	{
		if (game->ui_info.on_start == true)
		{
			mlx_clear_window(game->mlx, game->win);
			game->start = true;
			textures(game);
			set_ui(game);
			render_general(game);
			return (1);
		}
		else if (game->ui_info.on_exit == true)
			destroy_win(game);
	}
	else if (key == XK_Down || key == XK_Up)
		switch_menu(game);
	menu(game);
	return (0);
}

void	init_menu(t_game *game)
{
	game->start = false;
	game->ui_info.on_start = true;
	game->menu.add = mlx_xpm_file_to_image(game->mlx, "textures/menu.xpm",
			&game->menu.w, &game->menu.h);
	check_xpm(game, game->menu.add);
	game->menu.data_add = mlx_get_data_addr(game->menu.add,
			&(game->menu.bits_per_pixel),
			&(game->menu.line_length), &(game->menu.endian));
}
