#include "../include/cub3d.h"

int	destroy_win(t_game *game)
{
	destroy_image(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_gcclear(game->p);
	exit(0);
	return (0);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->menu.add);
	if (game->start == true)
	{
		mlx_destroy_image(game->mlx, game->head.add);
		mlx_destroy_image(game->mlx, game->health.add);
		mlx_destroy_image(game->mlx, game->ammo.add);
		mlx_destroy_image(game->mlx, game->weapons.add);
		mlx_destroy_image(game->mlx, game->gun.add);
		mlx_destroy_image(game->mlx, game->icon.add);
		mlx_destroy_image(game->mlx, game->aim.add);
		mlx_destroy_image(game->mlx, game->paused.add);
		mlx_destroy_image(game->mlx, game->scene.add);
		mlx_destroy_image(game->mlx, game->start_anim.add);
		mlx_destroy_image(game->mlx, game->the_doors.add);
		mlx_destroy_image(game->mlx, game->north.add);
		mlx_destroy_image(game->mlx, game->south.add);
		mlx_destroy_image(game->mlx, game->east.add);
		mlx_destroy_image(game->mlx, game->west.add);
		destroy_monsters(game);
		if (game->ui_info.health != 0)
		{
			mlx_destroy_image(game->mlx, game->minimap[0].add);
			mlx_destroy_image(game->mlx, game->minimap[1].add);
		}
	}
}

int	destroy_add(t_game *game)
{
	int	i;

	if (game->add_tab != NULL)
	{
		i = 0;
		while (game->add_tab[i])
		{
			mlx_destroy_image(game->mlx, game->add_tab[i]);
			i++;
		}
	}
	return (0);
}

void	destroy_monsters(t_game *game)
{
	mlx_destroy_image(game->mlx, game->injure.add);
	mlx_destroy_image(game->mlx, game->congrat.add);
	mlx_destroy_image(game->mlx, game->monster.add);
	mlx_destroy_image(game->mlx, game->boss.boss.add);
}
