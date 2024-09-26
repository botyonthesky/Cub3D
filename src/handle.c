#include "../include/cub3d.h"

int	handle_mouse(int x, int y, t_game *game)
{
	static int		lock = 0;
	static int		prev_x = 0;
	static double	velocity = 0;
	int				dx;

	(void)y;
	if (lock == 0)
		prev_x = x;
	dx = x - prev_x;
	velocity = 0.0010 * dx + (1 - 0.0010) * velocity;
	prev_x = x;
	if ((dx < 0 && velocity > 0) || (dx > 0 && velocity < 0))
		return (0);
	if (velocity < -4)
		velocity = -4;
	if (velocity > 4)
		velocity = 4;
	game->player.a = ft_mod(game->player.a + velocity * game->c, game->c * 360);
	lock = 1;
	return (0);
}

int	handle_keyboard(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		destroy_win(game);
	else if (keysym == XK_p)
		switch_pause(game);
	save_player_old_position(game);
	check_for_door(game);
	check_for_monster(game);
	check_for_boss(game);
	if (keysym == XK_e)
		switch_doors(game);
	keyboard_wasd(keysym, game);
	keyboard_left_right(keysym, game);
	keyboard_weapons(keysym, game);
	check_player_new_position(game);
	return (0);
}

void	keyboard_left_right(int keysym, t_game *game)
{
	if (keysym == XK_Left)
		game->player.a = (ft_mod(game->player.a - game->c * 1, game->c * 360));
	else if (keysym == XK_Right)
		game->player.a = (ft_mod(game->player.a + game->c * 1, game->c * 360));
}

void	keyboard_weapons(int keysym, t_game *game)
{
	if (keysym == XK_c && game->ui_info.health > 0)
		switch_weapons(game);
	else if (keysym == XK_f && game->ui_info.health > 0)
		manage_fire(game);
	else if (keysym == XK_1)
		select_weapons(game, PISTOL);
	else if (keysym == XK_2)
		select_weapons(game, SHOTGUN);
	else if (keysym == XK_3)
		select_weapons(game, CANON);
	else if (keysym == XK_4)
		select_weapons(game, GRENADE);
	else if (keysym == XK_5)
		select_weapons(game, EXPANDER);
}

void	keyboard_wasd(int keysym, t_game *game)
{
	if (keysym == XK_Up || keysym == XK_w)
	{
		game->player.x += SPEED * game->cos_t[game->player.a];
		game->player.y += SPEED * game->sin_t[game->player.a];
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		game->player.x -= SPEED * game->cos_t[game->player.a];
		game->player.y -= SPEED * game->sin_t[game->player.a];
	}
	else if (keysym == XK_d)
	{
		game->player.x -= SPEED * game->cos_t[ft_mod(game->player.a
				- game->c * 90, game->c * 360)];
		game->player.y -= SPEED * game->sin_t[ft_mod(game->player.a
				- game->c * 90, game->c * 360)];
	}
	else if (keysym == XK_a)
	{
		game->player.x -= SPEED * game->cos_t[ft_mod(game->player.a
				+ game->c * 90, game->c * 360)];
		game->player.y -= SPEED * game->sin_t[ft_mod(game->player.a
				+ game->c * 90, game->c * 360)];
	}
}
