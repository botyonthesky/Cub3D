#include "../../include/cub3d.h"

void	select_weapons(t_game *game, int selection)
{
	game->anim.nb_anim_gun_shoot = 0;
	game->anim.nb_anim_shotgun = 0;
	game->anim.nb_anim_canon = 0;
	game->anim.nb_anim_grenade = 0;
	game->anim.nb_anim_expander = 0;
	if (selection == PISTOL)
	{
		assign_weapons_bool(game, PISTOL);
		assign_pistol_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.bull;
	}
	else if (selection == SHOTGUN)
	{
		assign_weapons_bool(game, SHOTGUN);
		assign_shotgun_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.shotg;
	}
	else
		select_weapons2(game, selection);
}

void	select_weapons2(t_game *game, int selection)
{
	if (selection == CANON)
	{
		assign_weapons_bool(game, CANON);
		assign_canon_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.full_metal;
	}
	if (selection == GRENADE)
	{
		assign_weapons_bool(game, GRENADE);
		assign_grenade_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.grenades;
	}
	if (selection == EXPANDER)
	{
		assign_weapons_bool(game, EXPANDER);
		assign_expander_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.expanders;
	}
}

void	switch_weapons(t_game *game)
{
	game->anim.nb_anim_gun_shoot = 0;
	game->anim.nb_anim_shotgun = 0;
	game->anim.nb_anim_canon = 0;
	game->anim.nb_anim_grenade = 0;
	game->anim.nb_anim_expander = 0;
	if (game->ui_info.pistol == true)
	{
		assign_weapons_bool(game, SHOTGUN);
		assign_shotgun_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.shotg;
	}
	else if (game->ui_info.shotgun == true)
	{
		assign_weapons_bool(game, CANON);
		assign_canon_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.full_metal;
	}
	else
		switch_weapons2(game);
}

void	switch_weapons2(t_game *game)
{
	if (game->ui_info.canon == true)
	{
		assign_weapons_bool(game, GRENADE);
		assign_grenade_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.grenades;
	}
	else if (game->ui_info.grenade == true)
	{
		assign_weapons_bool(game, EXPANDER);
		assign_expander_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.expanders;
	}
	else if (game->ui_info.expander == true)
	{
		assign_weapons_bool(game, PISTOL);
		assign_pistol_bool(game, IDLE);
		game->ui_info.ammo = game->ui_info.bull;
	}
}

void	manage_pos_weapons(t_game *game, int x, int y)
{
	if (game->ui_info.pistol == true)
		mlx_put_image_to_window(game->mlx, game->win,
			game->gun.add, x - 30, y + 155);
	if (game->ui_info.shotgun == true)
		mlx_put_image_to_window(game->mlx, game->win,
			game->gun.add, x - 50, y + 110);
	else if (game->ui_info.canon == true)
		mlx_put_image_to_window(game->mlx, game->win,
			game->gun.add, x - 60, y);
	else if (game->ui_info.grenade == true)
		mlx_put_image_to_window(game->mlx, game->win,
			game->gun.add, x - 105, y + 45);
	else if (game->ui_info.grenade == true)
		mlx_put_image_to_window(game->mlx, game->win,
			game->gun.add, x - 50, y + 45);
}
