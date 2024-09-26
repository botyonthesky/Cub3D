#include "../../include/cub3d.h"

void	monsters_info(t_game *game)
{
	int	i;
	int	x;
	int	y;
	int	index;

	i = 0;
	x = 0;
	y = 0;
	index = 0;
	if (game->nb_monster != 0)
	{
		while (i < game->map.size)
		{
			if (game->map.grid[i] == 3)
			{
				x = (i % game->map.width) * 16 + 8;
				y = (i / game->map.width) * 16 + 8;
				add_monster_pos(game, (float)x, (float)y, index);
				index++;
			}
			i++;
		}
	}
}

void	add_monster_pos(t_game *game, float pos_x, float pos_y, int index)
{
	if (index >= 0 && index < game->nb_monster)
	{
		game->monster_pos[index].x = pos_x;
		game->monster_pos[index].y = pos_y;
		game->monster_pos[index].near = false;
		game->monster_pos[index].alive = true;
		game->monster_pos[index].health = 99;
	}
}

void	check_for_monster(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = game->player.x;
	y = game->player.y;
	while (i < game->nb_monster)
	{
		if (x >= game->monster_pos[i].x - 20
			&& x <= game->monster_pos[i].x + 20)
		{
			if (y >= game->monster_pos[i].y - 100
				&& y <= game->monster_pos[i].y + 100)
				game->monster_pos[i].near = true;
			else
				game->monster_pos[i].near = false;
		}
		else
			game->monster_pos[i].near = false;
		i++;
	}
}

void	manage_monster(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_monster)
	{
		if (game->ui_info.shoot_on_mob == true
			&& game->monster_pos[i].near == true)
		{
			if (game->monster_pos[i].health < 90
				&& game->monster_pos[i].health >= 70)
				change_monster_sprite(game, "textures/monster/monster.xpm");
			else if (game->monster_pos[i].health < 70
				&& game->monster_pos[i].health >= 50)
				change_monster_sprite(game, "textures/monster/monster2.xpm");
			else if (game->monster_pos[i].health < 50
				&& game->monster_pos[i].health >= 20)
				change_monster_sprite(game, "textures/monster/monster3.xpm");
			else if (game->monster_pos[i].health < 20)
				change_monster_sprite(game, "textures/monster/monster4.xpm");
		}
		i++;
	}
	return ;
}
