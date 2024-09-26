/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucravoi <lucravoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:38:28 by lucravoi          #+#    #+#             */
/*   Updated: 2024/05/15 14:05:02 by lucravoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_gc	*p;
	t_game	game;

	p = NULL;
	ft_memset(&game, 0, sizeof(game));
	game.map.c_c.c = -1;
	game.map.f_c.c = -1;
	check_args(ac, av);
	if (check_map(&p, &game.map, av[1]) == false
		|| fill_map_grid(&p, &game.map) == false)
		ft_gcclear(&p);
	else
	{
		game.p = &p;
		start_menu(&p, &game);
		ft_gcclear(&p);
	}
	return (0);
}
