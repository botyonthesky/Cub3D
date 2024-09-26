#include "../include/cub3d.h"

void	assign_weapons_bool(t_game *game, int selection)
{
	if (selection == PISTOL)
	{
		game->ui_info.pistol = true;
		game->ui_info.shotgun = false;
		game->ui_info.canon = false;
		game->ui_info.grenade = false;
		game->ui_info.expander = false;
	}
	else if (selection == SHOTGUN)
	{
		game->ui_info.pistol = false;
		game->ui_info.shotgun = true;
		game->ui_info.canon = false;
		game->ui_info.grenade = false;
		game->ui_info.expander = false;
	}
	else
		assign_weapons_bool2(game, selection);
}

void	assign_weapons_bool2(t_game *game, int selection)
{
	if (selection == CANON)
	{
		game->ui_info.pistol = false;
		game->ui_info.shotgun = false;
		game->ui_info.canon = true;
		game->ui_info.grenade = false;
		game->ui_info.expander = false;
	}
	if (selection == GRENADE)
	{
		game->ui_info.canon = false;
		game->ui_info.shotgun = false;
		game->ui_info.pistol = false;
		game->ui_info.grenade = true;
		game->ui_info.expander = false;
	}
	if (selection == EXPANDER)
	{
		game->ui_info.canon = false;
		game->ui_info.shotgun = false;
		game->ui_info.pistol = false;
		game->ui_info.grenade = false;
		game->ui_info.expander = true;
	}
}

void	*get_add(t_game *game, void *add)
{
	int	i;

	i = 0;
	while (i < 22)
	{
		if (game->add_tab[i] == NULL)
		{
			game->add_tab[i] = add;
			return (game->add_tab);
		}
		i++;
	}
	return (game->add_tab);
}

int	check_xpm(t_game *game, void *add)
{
	if (add == NULL)
		error_xpm(game);
	add = get_add(game, add);
	return (EXIT_SUCCESS);
}

int	error_xpm(t_game *game)
{
	write(STDERR_FILENO, ERROR, 50);
	destroy_add(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_gcclear(game->p);
	exit(0);
	return (EXIT_SUCCESS);
}
