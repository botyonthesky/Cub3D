#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "rays.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <curses.h>

# define USAGE "Usage ./cub3D {map}.cub\n"
# define FORMAT "Error\nMap format:\n	NO /path/to/north_texture\n\
	SO /path/to/south_texture\n\
	WE /path/to/west_texture\n\
	EA /path/to/east_texture\n\n\
	F {floor color in rgb values coma separated}\n\
	C {ceiling color in rgb values coma separated}\n\n\
	{map values:\n		0: empty space\n		1: wall\n\
		{N, S, W, E}: player spawn and orientation}\n"
# define ERROR "Error: Cannot load the .xpm file, check the path\n"
# define PISTOL 1
# define SHOTGUN 2
# define CANON 3
# define GRENADE 4
# define EXPANDER 5
# define RETURN 6
# define RESTART 7
# define QUIT 8
# define START 9
# define EXIT 10
# define OPEN 11
# define CLOSE 12
# define IDLE 13
# define SHOOT 14
# define MAX_DOORS 5
# define MAX_MONSTER 5
# define FOV 60
# define MMAP 200
# define HMMAP 100
# define SPEED 1

typedef struct s_points
{
	float	x;
	float	y;
	int		x3d;
	int		y3d;
	float	z3d;
	float	px;
	float	pz;
	float	ry;
	float	rz;
	float	yx;
	float	yy;
}				t_points;

typedef struct s_circle
{
	int		x;
	int		y;
	int		cx;
	int		cy;
	int		r;
}				t_circle;

typedef struct s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_line;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		points;
	int		i;
}				t_bresenham;

typedef struct s_strtok
{
	char	*str;
	char	*i_saveptr;
	char	*i_token;
	char	*o_saveptr;
	char	*o_token;
}				t_strtok;

typedef struct s_img
{
	int		w;
	int		h;
	void	*add;
	char	*data_add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_ui_info
{
	int		ammo;
	int		health;
	int		w1;
	int		w2;
	int		w3;
	int		bull;
	int		shotg;
	int		full_metal;
	int		grenades;
	int		expanders;
	int		bull_max;
	int		shotg_max;
	int		fm_max;
	int		grenade_max;
	int		expander_max;
	bool	pistol;
	bool	shotgun;
	bool	canon;
	bool	grenade;
	bool	expander;
	bool	paused;
	bool	on_start;
	bool	on_load;
	bool	on_exit;
	bool	on_return;
	bool	on_restart;
	bool	on_save;
	bool	on_quit;
	bool	shoot_on_mob;
}			t_ui_info;

typedef struct s_anim
{
	bool	start;
	int		nb_anim_gun_shoot;
	bool	gun_idle;
	bool	gun_shoot;
	int		nb_anim_shotgun;
	bool	shotgun_idle;
	bool	shotgun_shoot;
	int		nb_anim_canon;
	bool	canon_idle;
	bool	canon_shoot;
	int		nb_anim_grenade;
	bool	grenade_idle;
	bool	grenade_shoot;
	int		nb_anim_expander;
	bool	expander_idle;
	bool	expander_shoot;
	int		nb_anim_door_open;
	int		nb_anim_door_close;
	int		nb_anim_monster_walk;
	int		nb_anim_monster_fire;
	int		nb_anim_start;
	int		frame_gun_shoot;
	int		frame_shotgun;
	int		frame_canon;
	int		frame_grenade;
	int		frame_expander;
	int		frame_door_open;
	int		frame_door_close;
	int		frame_monster_walk;
	int		frame_monster_fire;
	int		frame_start;
	bool	still_shoot;
}				t_anim;

typedef struct s_player
{
	int		a;
	int		p;
	int		o_p;
	float	x;
	float	y;
	float	o_x;
	float	o_y;
	float	wx;
	float	wy;
	int		old_mouse_x;
	int		mob_in_sight;
	float	init_x;
	float	init_y;
	float	init_p;
	int		init_a;
}				t_player;

typedef struct s_door
{
	int		p;
	bool	near;
	bool	open;
	bool	close;
	bool	first;
	float	x;
	float	y;
	t_img	door;
}			t_door;

typedef struct s_monster
{
	float	x;
	float	y;
	int		health;
	bool	alive;
	bool	near;
	t_img	monster;
}			t_monster;

typedef struct s_boss
{
	float	x;
	float	y;
	int		health;
	bool	alive;
	bool	near;
	t_img	boss;
}			t_boss;

typedef struct s_map
{
	int		map;
	int		f_no;
	int		f_so;
	int		f_we;
	int		f_ea;
	t_color	f_c;
	t_color	c_c;
	int		*grid;
	int		spawn_set;
	int		size;
	int		width;
	int		height;
	char	s[30];
	float	*rays;
	int		*rays_o;
	float	*rays_x;
}				t_map;

typedef struct s_game
{
	t_player		player;
	void			*mlx;
	void			*win;
	t_map			map;
	float			*cos_t;
	float			*sin_t;
	bool			start;
	void			**add_tab;
	int				nb_door;
	int				nb_monster;
	int				monster_index;
	bool			switch_door;
	t_door			door_pos[MAX_DOORS];
	t_monster		monster_pos[MAX_MONSTER];
	t_boss			boss;
	t_anim			anim;
	t_img			the_doors;
	t_img			menu;
	t_img			start_anim;
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
	t_img			gun;
	t_img			ammo;
	t_img			weapons;
	t_img			health;
	t_img			head;
	t_img			icon;
	t_img			injure;
	t_img			monster;
	t_img			congrat;
	t_img			aim;
	t_img			paused;
	t_img			minimap[2];
	t_img			scene;
	t_ui_info		ui_info;
	t_gc			**p;
	int				c;
	int				w;
	int				h;
}		t_game;

/*------------------------Base-------------------------*/

int				main(int ac, char **av);

/*------------------------Parsing----------------------*/

bool			assign_map_colors(t_color *color, t_strtok *t);
void			check_args(int ac, char **av);
bool			check_map_colors(t_map *map, t_strtok *t);
bool			check_map_grid(t_map *map, char *line);
bool			check_map_spawn(t_map *map);
bool			check_map_texture_path(t_gc **p, int *fd, t_strtok *t);
bool			check_map_texture(t_gc **p, t_map *map, t_strtok *t);
bool			check_map(t_gc **p, t_map *map, char *path_to_map);
bool			fill_grid(t_map *map, int i);
bool			fill_map_grid(t_gc **p, t_map *map);
char			*fill_map_grid_init(t_gc **p, t_map *map);
bool			floodfill_line(int *grid, int max, int *min, int inc);
bool			floodfill(t_map *map);
char			*gnl_check(t_gc **p, char *line);
void			print_map(t_map *map);
void			replace_values_map_grid(t_map *map);
void			replace_all_doors(t_map *map);
int				check_for_doors(t_game *game, int p);

/*------------------------Raycasting-------------------*/

void			has_mob_in_sight(t_game *game, struct s_rays *r);
bool			is_inside_circle(t_circle *c);
void			draw_outer_circle(t_img *img, t_circle *p, int fill_color);
void			textures(t_game *game);
void			init_minimap_and_scene(t_game *game);
void			trig_tables(t_gc **p, t_game *game);
void			draw_scene(t_game *game);
void			draw_minimap(t_game *game);
void			draw_minimap_grid(t_game *game);
void			player_info(t_game *game);
void			bresenham_draw(t_line *p, t_bresenham *b, t_img *img,
					int color);
void			draw_point(t_img *img, t_line *p, int color);
void			bresenham_init(t_line *p, t_bresenham *b);
void			draw_square(t_img *img, t_line *p, int color, bool inner);
void			draw_line(t_img *img, t_line *p, int color);
void			draw_circle(t_img *img, t_circle *p, int color);
void			draw_circle_points(t_img *img, t_line *p, int color);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				mlx_get_pixel_color(t_img *img, int x, int y);
void			draw_minimap_rays(t_game *game);
void			horizontal_ray(t_game *game, struct s_rays *r);
void			vertical_ray(t_game *game, struct s_rays *r);
bool			vertical_point(t_game *game, struct s_rays *r);
bool			horizontal_point(t_game *game, struct s_rays *r);
int				is_an_horizontal_wall(t_game *game, float x, float y);
int				is_a_vertical_wall(t_game *game, float x, float y);
void			draw_rays(t_game *game, struct s_rays *r);
void			player_info(t_game *game);
void			circle_minimap(t_game *game);
void			red_laser(t_game *game, struct s_rays *r);
void			print_coordinates(t_game *game);

/*------------------------Player-----------------------*/

void			player_info(t_game *game);
void			save_player_old_position(t_game *game);
void			check_player_new_position_corner(t_game *game);
void			check_player_new_position(t_game *game);

/*------------------------Render-----------------------*/

int				render_general(t_game *game);
int				render_ui(t_game *game);
int				my_loop_hook(t_game *game);

/*------------------------Handle-----------------------*/

int				handle_mouse(int x, int y, t_game *game);
int				handle_keyboard(int keysym, t_game *game);
void			keyboard_weapons(int keysym, t_game *game);
void			keyboard_wasd(int keysym, t_game *game);
void			keyboard_left_right(int keysym, t_game *game);

/*------------------------Menu-----------------------*/

void			init_menu(t_game *game);
void			start_menu(t_gc **p, t_game *game);
int				menu(t_game *game);
int				handle_menu(int key, t_game *game);
void			select_menu(t_game *game);
int				switch_menu(t_game *game);	

/*------------------------Mouse-----------------------*/

int				handle_mouse(int x, int y, t_game *game);

/*------------------------UI----------------------------*/

void			set_ui(t_game *game);
void			init_ui(t_game *game);
void			put_ui_image(t_game *game);
void			put_ui_info(t_game *game);
void			put_next(t_game *game, int x, int y);
void			put_ui_detail(t_game *game);
void			put_ui_detail_max(t_game *game);

/*------------------------Animations--------------------*/

void			init_anim(t_game *game);
void			init_frame(t_game *game);
void			init_add(t_game *game);
void			init_add2(t_game *game);
void			init_injure_add(t_game *game);
void			init_data_add(t_game *game);
void			init_door(t_game *game);
void			init_monster(t_game *game);
void			init_boss(t_game *game);

/*----------------Start----------------------*/

int				anim_loop_start(t_game *game);
void			anim_start(t_game *game);
void			update_frame_start(t_game *game);
void			anim_start(t_game *game);
void			change_start_sprite(t_game *game, char *path);
void			start_anim(t_game *game);
void			start_anim2(t_game *game);

/*----------------Doors----------------------*/

void			manage_door(t_game *game);
void			door_info(t_game *game);
void			init_restart(t_game *game);
void			add_door_pos(t_game *game, float pos_x, float pos_y, int index);
void			switch_doors(t_game *game);
int				open_door(t_game *game);
int				close_door(t_game *game);
int				anim_loop_door_opened(t_game *game);
int				anim_loop_door_closed(t_game *game);
int				anim_door_opened(t_game *game);
void			update_frame_door_opened(t_game *game);
void			door_open_anim(t_game *game);
void			anim_door_closed(t_game *game);
void			update_frame_door_closed(t_game *game);
void			door_closed_anim(t_game *game);
void			check_for_door(t_game *game);
void			assign_door_bool(t_game *game, int i, int selection);
void			change_door_sprite(t_game *game, char *path);

/*----------------Monsters-------------------*/

void			add_monster_pos(t_game *game, float pos_x, float pos_y,
					int index);
void			monsters_info(t_game *game);
void			manage_monster(t_game *game);
void			manage_monster_health(t_game *game, int i);
void			change_monster_sprite(t_game *game, char *path);
void			destroy_monsters(t_game *game);
void			check_for_monster(t_game *game);
void			check_monster_shoot(t_game *game);
void			boss_info(t_game *game);
void			check_for_boss(t_game *game);
void			manage_boss(t_game *game);
void			change_boss_sprite(t_game *game, char *path);
void			check_boss_shoot(t_game *game);
void			manage_boss_health(t_game *game);

/*----------------Pistol---------------------*/

void			anim_gun_shoot(t_game *game);
void			update_frame_gun_shoot(t_game *game);
void			gun_shoot_anim(t_game *game);
int				anim_loop_gun_idle(t_game *game);
int				manage_gun_fire(t_game *game);
void			assign_pistol_bool(t_game *game, int selection);
void			change_gun_sprite(t_game *game, char *path);

/*----------------Shotgun---------------------*/

void			anim_shotgun(t_game *game);
void			update_frame_shotgun(t_game *game);
void			shotgun_anim(t_game *game);
void			shotgun_anim_2(t_game *game);
int				anim_loop_shotgun_idle(t_game *game);
int				manage_shotgun_fire(t_game *game);
void			assign_shotgun_bool(t_game *game, int selection);

/*----------------Canon---------------------*/

void			anim_canon(t_game *game);
void			update_frame_canon(t_game *game);
void			canon_anim(t_game *game);
void			canon_anim2(t_game *game);
int				anim_loop_canon_idle(t_game *game);
int				manage_canon_fire(t_game *game);
void			assign_canon_bool(t_game *game, int selection);

/*------------------Grenade-------------------*/

void			anim_grenade(t_game *game);
void			update_frame_grenade(t_game *game);
void			grenade_anim(t_game *game);
int				anim_loop_grenade_idle(t_game *game);
int				manage_grenade_fire(t_game *game);
void			assign_grenade_bool(t_game *game, int selection);

/*------------------Expander-------------------*/

void			update_frame_expander(t_game *game);
void			anim_expander(t_game *game);
void			expander_anim(t_game *game);
void			expander_anim2(t_game *game);
int				anim_loop_expander_idle(t_game *game);
int				manage_expander_fire(t_game *game);
void			assign_expander_bool(t_game *game, int selection);

/*-----------------------Menu Pause----------------------*/

int				manage_pause(t_game *game);
int				handle_key(int key, t_game *game);
int				switch_return(t_game *game, int select);
void			switch_pause(t_game *game);
void			select_line(t_game *game);
int				switch_menu(t_game *game);

/*---------------------------Weapons---------------------*/

void			select_weapons(t_game *game, int selection);
void			select_weapons2(t_game *game, int selection);
void			switch_weapons(t_game *game);
void			switch_weapons2(t_game *game);
void			manage_ui_weapons(t_game *game);
void			manage_pos_weapons(t_game *game, int x, int y);
void			manage_fire(t_game *game);

/*---------------------------Health---------------------*/

void			manage_injure(t_game *game);

/*----------------------------MLX Perso--------------------*/

unsigned int	mlx_get_pixel_img(t_img img, int x, int y);
void			mlx_put_pixel_img(t_img img, int x, int y, int color);
void			mlx_put_img_to_img(t_img dst, t_img src, int x, int y);
void			manage_img_to_img(t_game *game);

/*----------------------------Utils--------------------*/

void			assign_weapons_bool(t_game *game, int selection);
void			assign_weapons_bool2(t_game *game, int selection);
int				assign_pause_bool(t_game *game, int selection);
int				assign_menu_bool(t_game *game, int selection);
void			set_string_font(t_game *game, int x, int y, int selection);
void			set_string_font2(t_game *game, int x, int y, int selection);
void			set_string_font3(t_game *game, int x, int y, int selection);
void			*get_add(t_game *game, void *add);
void			init_add_tab(t_game *game);
int				check_xpm(t_game *game, void *add);
int				error_xpm(t_game *game);

/*------------------------Destroy All--------------------*/

int				destroy_win(t_game *game);
void			destroy_image(t_game *game);
int				destroy_add(t_game *game);

#endif
