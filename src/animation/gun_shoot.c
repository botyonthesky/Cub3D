#include "../../include/cub3d.h"

int	manage_gun_fire(t_game *game)
{
	assign_weapons_bool(game, PISTOL);
	if (game->ui_info.ammo <= 0)
		return (1);
	game->ui_info.ammo--;
	game->ui_info.bull--;
	game->anim.frame_gun_shoot = 0;
	assign_pistol_bool(game, SHOOT);
	check_monster_shoot(game);
	check_boss_shoot(game);
	return (0);
}

void	anim_gun_shoot(t_game *game)
{
	if (game->anim.nb_anim_gun_shoot < 8000)
	{
		game->anim.nb_anim_gun_shoot++;
		return ;
	}
	game->anim.nb_anim_gun_shoot = 0;
	update_frame_gun_shoot(game);
	gun_shoot_anim(game);
	render_ui(game);
}

void	update_frame_gun_shoot(t_game *game)
{
	if (game->anim.frame_gun_shoot < 6)
		game->anim.frame_gun_shoot++;
	else
		game->anim.frame_gun_shoot = 1;
}

void	gun_shoot_anim(t_game *game)
{
	if (game->anim.frame_gun_shoot == 1)
		change_gun_sprite(game, "textures/gun/gunshoot.xpm");
	else if (game->anim.frame_gun_shoot == 2)
		change_gun_sprite(game, "textures/gun/gunshoot2.xpm");
	else if (game->anim.frame_gun_shoot == 3)
		change_gun_sprite(game, "textures/gun/gunshoot3.xpm");
	else if (game->anim.frame_gun_shoot == 4)
		change_gun_sprite(game, "textures/gun/gunshoot4.xpm");
	else if (game->anim.frame_gun_shoot == 5)
	{
		change_gun_sprite(game, "textures/gun/gunshoot.xpm");
		assign_pistol_bool(game, IDLE);
		manage_monster(game);
		if (game->boss.health > 0)
			manage_boss(game);
	}
}
