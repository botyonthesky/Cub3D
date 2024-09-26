#include "../../include/cub3d.h"

void	put_ui_info(t_game *game)
{
	char	ammo[12];
	char	health[12];
	int		x;
	int		y;

	x = game->w / 2;
	y = game->h / 2;
	ft_memcpy(ammo, ft_itoa(game->ui_info.ammo), 12);
	ft_memcpy(health, ft_itoa(game->ui_info.health), 12);
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-85-*-*-*-*-*-*-*");
	mlx_string_put(game->mlx, game->win, x - 400, y + 380, 0xFF0000, ammo);
	mlx_string_put(game->mlx, game->win, x - 250, y + 380, 0xFF0000, health);
	mlx_string_put(game->mlx, game->win, x - 122, y + 380, 0xFF0000, "%" );
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-30-*-*-*-*-*-*-*");
	mlx_string_put(game->mlx, game->win, game->w - 300, 50,
		0x000000, game->map.s);
	put_ui_detail(game);
	put_ui_detail_max(game);
}

void	put_ui_detail(t_game *game)
{
	char	bull[12];
	char	shotg[12];
	char	canon[12];
	int		x;
	int		y;

	x = game->w / 2;
	y = game->h / 2;
	ft_memcpy(bull, ft_itoa(game->ui_info.bull), 12);
	ft_memcpy(shotg, ft_itoa(game->ui_info.shotg), 12);
	ft_memcpy(canon, ft_itoa(game->ui_info.full_metal), 12);
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-26-*-*-*-*-*-*-*");
	mlx_string_put(game->mlx, game->win, x + 420, y + 315, -1, bull);
	mlx_string_put(game->mlx, game->win, x + 453, y + 315, -1, "/");
	mlx_string_put(game->mlx, game->win, x + 420, y + 343, -1, shotg);
	mlx_string_put(game->mlx, game->win, x + 453, y + 343, -1, "/");
	mlx_string_put(game->mlx, game->win, x + 420, y + 370, -1, canon);
	mlx_string_put(game->mlx, game->win, x + 453, y + 370, -1, "/");
	put_next(game, x, y);
}

void	put_next(t_game *game, int x, int y)
{
	char	grenade[12];
	char	grenade_m[12];
	char	expander[12];
	char	expander_m[12];

	ft_memcpy(grenade, ft_itoa(game->ui_info.grenades), 12);
	ft_memcpy(grenade_m, ft_itoa(game->ui_info.grenade_max), 12);
	ft_memcpy(expander, ft_itoa(game->ui_info.expanders), 12);
	ft_memcpy(expander_m, ft_itoa(game->ui_info.expander_max), 12);
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-26-*-*-*-*-*-*-*");
	mlx_string_put(game->mlx, game->win, x + 420, y + 400, -1, grenade);
	mlx_string_put(game->mlx, game->win, x + 453, y + 400, -1, "/");
	mlx_string_put(game->mlx, game->win, x + 465, y + 400, -255, grenade_m);
	mlx_string_put(game->mlx, game->win, x + 420, y + 430, -1, expander);
	mlx_string_put(game->mlx, game->win, x + 453, y + 430, -1, "/");
	mlx_string_put(game->mlx, game->win, x + 465, y + 430, -255, expander_m);
}

void	put_ui_detail_max(t_game *game)
{
	char	bull_max[12];
	char	shotg_max[12];
	char	canon_max[12];
	int		x;
	int		y;

	x = game->w / 2;
	y = game->h / 2;
	ft_memcpy(bull_max, ft_itoa(game->ui_info.bull_max), 12);
	ft_memcpy(shotg_max, ft_itoa(game->ui_info.shotg_max), 12);
	ft_memcpy(canon_max, ft_itoa(game->ui_info.fm_max), 12);
	mlx_set_font(game->mlx, game->win,
		"-schumacher-*-bold-*-*-*-26-*-*-*-*-*-*-*");
	mlx_string_put(game->mlx, game->win, x + 465, y + 315, -255, bull_max);
	mlx_string_put(game->mlx, game->win, x + 465, y + 343, -255, shotg_max);
	mlx_string_put(game->mlx, game->win, x + 465, y + 370, -255, canon_max);
}

void	put_ui_image(t_game *game)
{
	int	x;
	int	y;

	x = game->w / 2;
	y = game->h / 2;
	mlx_put_image_to_window(game->mlx, game->win,
		game->head.add, x - 75, y + 290);
	mlx_put_image_to_window(game->mlx, game->win,
		game->weapons.add, x + 120, y + 290);
	mlx_put_image_to_window(game->mlx, game->win,
		game->health.add, x - 270, y + 290);
	mlx_put_image_to_window(game->mlx, game->win,
		game->ammo.add, x - 455, y + 290);
	mlx_put_image_to_window(game->mlx, game->win,
		game->icon.add, x + 315, y + 290);
}
