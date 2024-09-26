#include "../../include/cub3d.h"

int	switch_return(t_game *game, int select)
{
	while (1)
	{
		if (game->ui_info.on_return == true)
		{
			if (select == 1)
				return (assign_pause_bool(game, RESTART));
			else
				return (assign_pause_bool(game, QUIT));
		}
		else if (game->ui_info.on_restart == true)
		{
			if (select == 1)
				return (assign_pause_bool(game, QUIT));
			else
				return (assign_pause_bool(game, RETURN));
		}
		else if (game->ui_info.on_quit == true)
		{
			if (select == 1)
				return (assign_pause_bool(game, RETURN));
			else
				return (assign_pause_bool(game, RESTART));
		}
	}
}

void	switch_pause(t_game *game)
{
	if (game->ui_info.paused == true)
		game->ui_info.paused = false;
	else
		game->ui_info.paused = true;
}

int	switch_menu(t_game *game)
{
	while (1)
	{
		if (game->ui_info.on_start == true)
			return (assign_menu_bool(game, EXIT));
		else if (game->ui_info.on_exit == true)
			return (assign_menu_bool(game, START));
	}
	return (0);
}
