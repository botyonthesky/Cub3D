#include "../../include/cub3d.h"

void	manage_injure(t_game *game)
{
	mlx_put_img_to_img(game->scene, game->injure, 0, 0);
	mlx_put_img_to_img(game->scene, game->congrat, 450, 450);
}
