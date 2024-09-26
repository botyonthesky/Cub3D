#include "../../include/cub3d.h"
#include "../../include/rays.h"

static void	draw_v_rays(t_game *game, struct s_rays *r)
{
	draw_line(&game->minimap[0], &(t_line){r->x, r->y, r->xn, r->yn},
		0x00FF00);
	game->map.rays[r->i] = r->r;
	game->map.rays_o[r->i] = r->o;
	game->map.rays_x[r->i] = fmod(r->yn, 16);
	if (game->player.a > game->c * 90 && game->player.a < game->c * 270)
		game->map.rays_x[r->i] = 16 - fmod(r->yn, 16);
	if (game->player.a == game->c * 270)
		game->map.rays_x[r->i] = fmod(r->xn, 16);
	if (game->player.a == game->c * 90)
		game->map.rays_x[r->i] = 16 - fmod(r->xn, 16);
}

static void	draw_h_rays(t_game *game, struct s_rays *r)
{
	draw_line(&game->minimap[0], &(t_line){r->x, r->y, r->xn2, r->yn2},
		0x00FF00);
	game->map.rays[r->i] = r->r2;
	game->map.rays_o[r->i] = r->o2;
	game->map.rays_x[r->i] = fmod(r->xn2, 16);
	if (game->player.a < game->c * 180)
		game->map.rays_x[r->i] = 16 - fmod(r->xn2, 16);
	if (game->player.a == game->c * 180)
		game->map.rays_x[r->i] = 16 - fmod(r->yn2, 16);
	if (game->player.a == 0)
		game->map.rays_x[r->i] = fmod(r->yn2, 16);
}

void	draw_rays(t_game *game, struct s_rays *r)
{
	if (r->r >= 0 && (r->r < r->r2 || r->r2 < 0))
		draw_v_rays(game, r);
	else
		draw_h_rays(game, r);
	game->map.rays_x[r->i] *= game->cos_t[abs(game->player.a - r->a)];
	game->map.rays[r->i] /= 8;
}
