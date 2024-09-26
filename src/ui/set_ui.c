#include "../../include/cub3d.h"

void	set_ui(t_game *game)
{
	init_ui(game);
	init_add(game);
	init_minimap_and_scene(game);
	draw_minimap(game);
	draw_scene(game);
}

void	init_minimap_and_scene(t_game *game)
{
	game->minimap[0].add = mlx_new_image(game->mlx, game->map.width * 16,
			game->map.height * 16);
	game->minimap[0].data_add = mlx_get_data_addr(game->minimap[0].add,
			&(game->minimap[0].bits_per_pixel), \
	&(game->minimap[0].line_length), &(game->minimap[0].endian));
	game->minimap[0].w = game->map.width * 16;
	game->minimap[0].h = game->map.height * 16;
	game->minimap[1].add = mlx_new_image(game->mlx, MMAP, MMAP);
	game->minimap[1].data_add = mlx_get_data_addr(game->minimap[1].add,
			&(game->minimap[1].bits_per_pixel), \
	&(game->minimap[1].line_length), &(game->minimap[1].endian));
	game->minimap[1].w = MMAP;
	game->minimap[1].h = MMAP;
	game->scene.add = mlx_new_image(game->mlx, game->w, game->h);
	game->scene.data_add = mlx_get_data_addr(game->scene.add,
			&(game->scene.bits_per_pixel), \
	&(game->scene.line_length), &(game->scene.endian));
	game->scene.w = game->w;
	game->scene.h = game->h;
}
