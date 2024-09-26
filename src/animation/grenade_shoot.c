#include "../../include/cub3d.h"

int	manage_grenade_fire(t_game *game)
{
	assign_weapons_bool(game, GRENADE);
	if (game->ui_info.ammo <= 0)
		return (1);
	game->ui_info.ammo--;
	game->ui_info.grenades--;
	game->anim.frame_grenade = 0;
	assign_grenade_bool(game, SHOOT);
	check_monster_shoot(game);
	check_boss_shoot(game);
	return (0);
}

void	anim_grenade(t_game *game)
{
	if (game->anim.nb_anim_grenade < 20000)
	{
		game->anim.nb_anim_grenade++;
		return ;
	}
	game->anim.nb_anim_grenade = 0;
	update_frame_grenade(game);
	grenade_anim(game);
	render_ui(game);
}

void	update_frame_grenade(t_game *game)
{
	if (game->anim.frame_grenade < 9)
		game->anim.frame_grenade++;
	else
		game->anim.frame_grenade = 1;
}

void	grenade_anim(t_game *game)
{
	if (game->anim.frame_grenade == 1)
		change_gun_sprite(game, "textures/grenade/grenade_hold.xpm");
	else if (game->anim.frame_grenade == 2)
		change_gun_sprite(game, "textures/grenade/grenade_shoot1.xpm");
	else if (game->anim.frame_grenade == 3)
		change_gun_sprite(game, "textures/grenade/grenade_shoot2.xpm");
	else if (game->anim.frame_grenade == 4)
		change_gun_sprite(game, "textures/grenade/grenade_shoot3.xpm");
	else if (game->anim.frame_grenade == 5)
		change_gun_sprite(game, "textures/grenade/grenade_shoot4.xpm");
	else if (game->anim.frame_grenade == 6)
		change_gun_sprite(game, "textures/grenade/grenade_shoot5.xpm");
	else if (game->anim.frame_grenade == 7)
		change_gun_sprite(game, "textures/grenade/grenade_shoot6.xpm");
	else if (game->anim.frame_grenade == 8)
	{
		change_gun_sprite(game, "textures/grenade/grenade_hold.xpm");
		assign_grenade_bool(game, IDLE);
		manage_monster(game);
		if (game->boss.health > 0)
			manage_boss(game);
	}
}
