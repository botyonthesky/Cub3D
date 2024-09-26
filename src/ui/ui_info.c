#include "../../include/cub3d.h"

void	manage_ui_weapons(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	if (game->ui_info.pistol == true)
		set_string_font(game, x, y, PISTOL);
	if (game->ui_info.shotgun == true)
		set_string_font(game, x, y, SHOTGUN);
	if (game->ui_info.canon == true)
		set_string_font(game, x, y, CANON);
	if (game->ui_info.grenade == true)
		set_string_font(game, x, y, GRENADE);
	if (game->ui_info.expander == true)
		set_string_font(game, x, y, EXPANDER);
}

void	set_string_font(t_game *game, int x, int y, int selection)
{
	if (selection == PISTOL)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-45-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x + 155, y + 350, 0xFFFF00, "1");
		mlx_string_put(game->mlx, game->win, x + 206, y + 350, -1, "2");
		mlx_string_put(game->mlx, game->win, x + 257, y + 350, -1, "3");
		mlx_string_put(game->mlx, game->win, x + 155, y + 397, -1, "4");
		mlx_string_put(game->mlx, game->win, x + 206, y + 397, -1, "5");
	}
	else if (selection == SHOTGUN)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-45-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x + 155, y + 350, -1, "1");
		mlx_string_put(game->mlx, game->win, x + 206, y + 350, 0xFFFF00, "2");
		mlx_string_put(game->mlx, game->win, x + 257, y + 350, -1, "3");
		mlx_string_put(game->mlx, game->win, x + 155, y + 397, -1, "4");
		mlx_string_put(game->mlx, game->win, x + 206, y + 397, -1, "5");
	}
	else
		set_string_font2(game, x, y, selection);
}

void	set_string_font2(t_game *game, int x, int y, int selection)
{
	if (selection == CANON)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-45-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x + 155, y + 350, -1, "1");
		mlx_string_put(game->mlx, game->win, x + 206, y + 350, -1, "2");
		mlx_string_put(game->mlx, game->win, x + 257, y + 350, 0xFFFF00, "3");
		mlx_string_put(game->mlx, game->win, x + 155, y + 397, -1, "4");
		mlx_string_put(game->mlx, game->win, x + 206, y + 397, -1, "5");
	}
	else if (selection == GRENADE)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-45-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x + 155, y + 350, -1, "1");
		mlx_string_put(game->mlx, game->win, x + 206, y + 350, -1, "2");
		mlx_string_put(game->mlx, game->win, x + 257, y + 350, -1, "3");
		mlx_string_put(game->mlx, game->win, x + 155, y + 397, 0xFFFF00, "4");
		mlx_string_put(game->mlx, game->win, x + 206, y + 397, -1, "5");
	}
	else
		set_string_font3(game, x, y, selection);
}

void	set_string_font3(t_game *game, int x, int y, int selection)
{
	if (selection == EXPANDER)
	{
		mlx_set_font(game->mlx, game->win,
			"-schumacher-*-bold-*-*-*-45-*-*-*-*-*-*-*");
		mlx_string_put(game->mlx, game->win, x + 155, y + 350, -1, "1");
		mlx_string_put(game->mlx, game->win, x + 206, y + 350, -1, "2");
		mlx_string_put(game->mlx, game->win, x + 257, y + 350, -1, "3");
		mlx_string_put(game->mlx, game->win, x + 155, y + 397, -1, "4");
		mlx_string_put(game->mlx, game->win, x + 206, y + 397, 0xFFFF00, "5");
	}
}

void	debug_mob(t_game *game)
{
	printf("mob %d\n", game->player.mob_in_sight);
	printf("shoot mob %d\n", game->ui_info.shoot_on_mob);
}
