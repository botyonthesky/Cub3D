#include "../../include/cub3d.h"

int	manage_expander_fire(t_game *game)
{
	assign_weapons_bool(game, EXPANDER);
	if (game->ui_info.ammo <= 0)
		return (1);
	game->ui_info.ammo--;
	game->ui_info.expanders--;
	game->anim.frame_expander = 0;
	assign_expander_bool(game, SHOOT);
	check_monster_shoot(game);
	check_boss_shoot(game);
	return (0);
}

void	anim_expander(t_game *game)
{
	if (game->anim.nb_anim_expander < 10000)
	{
		game->anim.nb_anim_expander++;
		return ;
	}
	game->anim.nb_anim_expander = 0;
	update_frame_expander(game);
	expander_anim(game);
	render_ui(game);
}

void	update_frame_expander(t_game *game)
{
	if (game->anim.frame_expander < 12)
		game->anim.frame_expander++;
	else
		game->anim.frame_expander = 1;
}

void	expander_anim(t_game *game)
{
	if (game->anim.frame_expander == 1)
		change_gun_sprite(game, "textures/expander/expander_shoot1.xpm");
	else if (game->anim.frame_expander == 2)
		change_gun_sprite(game, "textures/expander/expander_shoot2.xpm");
	else if (game->anim.frame_expander == 3)
		change_gun_sprite(game, "textures/expander/expander_shoot3.xpm");
	else if (game->anim.frame_expander == 4)
		change_gun_sprite(game, "textures/expander/expander_shoot4.xpm");
	else if (game->anim.frame_expander == 5)
		change_gun_sprite(game, "textures/expander/expander_shoot5.xpm");
	else if (game->anim.frame_expander == 6)
		change_gun_sprite(game, "textures/expander/expander_shoot6.xpm");
	else if (game->anim.frame_expander == 7)
		change_gun_sprite(game, "textures/expander/expander_shoot7.xpm");
	expander_anim2(game);
}

void	expander_anim2(t_game *game)
{
	if (game->anim.frame_expander == 8)
		change_gun_sprite(game, "textures/expander/expander_shoot8.xpm");
	else if (game->anim.frame_expander == 9)
		change_gun_sprite(game, "textures/expander/expander_shoot9.xpm");
	else if (game->anim.frame_expander == 10)
		change_gun_sprite(game, "textures/expander/expander_shoot10.xpm");
	else if (game->anim.frame_expander == 11)
	{
		change_gun_sprite(game, "textures/expander/expander_idle.xpm");
		assign_expander_bool(game, IDLE);
		manage_monster(game);
		if (game->boss.health > 0)
			manage_boss(game);
	}
}
