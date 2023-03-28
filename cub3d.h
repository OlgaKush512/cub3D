/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:20:27 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/08 11:23:29 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

# define RES_X 2048
# define RES_Y 1024
# define SCALING 3
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define FL_RIGHT 65363
# define FL_LEFT 65361

# define ESC 65307
# define PI 3.14159265359
# define PI2 1.57079632679
# define PI3 4.71238898038
# define DR 0.00054541562

# define MAP 109
# define BLUR +0x888888
# define MARGIN 100
# define OPACITY 0.5

# define SCALING 3

typedef struct s_rgb
{	
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	op;
}				t_rgb;

typedef struct s_vars
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		floor_col[3];
	int		ceiling_col[3];
	char	**map;
}			t_vars;

typedef struct s_state
{
	float	player_x;
	float	player_y;
	float	player_old_x;
	float	player_old_y;
	float	delta_x;
	float	delta_y;
	float	pa;
}				t_state;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}				t_map;

typedef struct s_draw
{
	int		i;
	int		j;
	int		k;
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		mod;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	yo;
	float	a_tan;
	float	n_tan;
	float	x;
	float	y;
	float	hdist;
	float	vdist;
	float	tdist;
	float	dis_ta;
	float	lineh;
	float	lineo;
	float	ca;
	float	saveh;
}				t_draw;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
	int		w;
	int		h;
	t_state	game_state;
	int		image_is_destroyed;
}			t_data;

typedef struct s_input
{
	int		xo;
	int		yo;
	int		posx;
	int		posx_add_xo;
	int		posx_sub_xo;
	int		posy;
	int		posy_add_yo;
	int		posy_sub_yo;
	int		posx_add_yo;
	int		posx_sub_yo;
	int		posy_add_xo;
	int		posy_sub_xo;
	int		res;
}				t_input;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	t_input		inp;
	t_draw		dr;
	t_data		img;
	t_data		txr[4];
	char		*path[4];
	t_data		sp;
	t_data		wall;
	t_data		space;
	t_data		ray;
	t_data		north;
	t_data		south;
	t_data		east;
	t_data		west;
	void		*image;
	void		*image_addr;
	int			disp;
	int			x;
	int			y;
	int			starting_x;
	int			starting_y;
	float		starting_angle;
	int			image_is_destroyed;
	int			nb_mvmt;
	int			total_col;
	int			taken_col;
	int			flag;
	int			bool_map;
	t_vars		*vars;
	int			map_x;
	int			map_y;
	int			*map;
	t_rgb		ceil_col;
	t_rgb		flo_col;
}				t_app;
/*main.c*/
int		ft_minimize(t_app *app);

/*parsing/check_arg.c*/
int		isgoodline(char *str);
int		check_extension(char *str);
int		try_open(char *str);
int		check_arg(char *av, int ac);

/*parsing/check_input_utils.c*/
int		ret_int_free(int ret, char *tofree);
int		good_id(char *str);
int		tab_len(char **tab);
int		check_file(char *str);
int		check_colour(char *str);

/*parsing/check_input.c*/
int		check_input(char *file);
int		check_lines(int fd);
int		check_map(char *str, int fd);
int		parse_line(char *str, int fd);

/*parsing/parsing_utils.c*/
int		second_args(char *str, char *id);
int		isonlyset(char *str, char *set);
int		two_nums(char *s1, const char *s2);
int		isonlyspace(char *str);
int		ret_int_free_3d(char **str, int ret);
/*parsing/store_data.c*/
t_vars	*get_data(char *str);
void	init_data(t_vars **data);

/*parsing/exit_utils.c*/
int		bad_malloc(void);
int		bad_fd(void);
void	free_data(t_vars *data);

/*parsing/parse_value.c*/
void	get_values(t_vars *data, int fd);
void	add_line(t_vars *data, char *str);
char	*skip_id(char *str);
void	add_col(t_vars *data, char *val, char c);

/*parsing/parse_map.c*/
void	get_map(t_vars *data, int fd);
void	add_map(char *first_line, int fd, t_vars *data);
void	add_map_line(char ***map, char *new);

/*parsing/check_data.c*/
void	check_data(t_vars *data);
int		check_player(t_vars *data);
int		check_walls(t_vars *data);
int		check_inside(t_vars *data);

/*parsing/check_data_utils.c*/
int		char_inset(char c, char *set);
int		full_line(char *str);
int		check_surround(char *check, char *prev, char *next);

/*parsing/print_data.c*/
void	print_data(t_vars *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put_line(t_app *app, int x, int y, int color);
void	init_colors(t_app *app);
void	init_app(t_app *app, char *title, int w, int h);
int		destroy_game_data(void *data, int i);
void	draw_sprite(t_app *app);
void	init_sprite(t_app *app);
void	drow_background(t_app *app);

/*init_map.c*/
int		isinset(char c, char *set);
void	add_starting_angle(t_app *app, char c, int j, int i);
int		*fill_map(int size, int longest, char **map, t_app *app);
void	init_map(t_app *app, char **map);

/*raycasting/input_keys.c */
void	arrow_left(t_app *app);
void	arrow_right(t_app *app);
void	arrow_input(t_app *app, int key);
void	pos_left_right(t_app *app, int key);
void	pos_down_up(t_app *app, int key);

/*raycasting/input_func.c*/
void	reinit_var_input(t_app *app);
int		player_input(int key, void *data);
int		player_input_body(int key, t_app *app);

/*actions.c*/
void	close_images(t_app *app, int i);
int		player_input(int key, void *data);
int		player_input_body(int key, t_app *app);
int		routine(void *data);
char	*copy_size(char *str, int bpp, int size);

/* draw_image.c*/
void	draw_img_at_pos(t_app *app, t_data *txr, int x, int y);
void	draw_img_at_pos_body(t_app *app, t_data *txr, int st, int bpp);
int		check_pixel(t_data *txr, int line, int col);
void	*bit_copy(void *dst, const void *src, int j);

/*destroy_and_free.c*/
void	free_paths(t_app *app);
int		destroy_game_data(void *data, int i);

/*draw_player_line.c*/
void	draw_line(t_app *app, int t);
int		check_size_map(int taille, t_app *app);
void	disp_player(t_app *app, int taille);

/*map.c*/
void	draw_line(t_app *app, int taille);
void	disp_player(t_app *app, int taille);
void	drow_element(t_app *app, int x, int y, int color);
void	draw_map(t_app *app);

/*draw_3dray.c*/
void	check_hor_down(t_app *app);
void	check_hor_up(t_app *app);
void	check_hor_left_right(t_app *app);
void	check_hor_action(t_app *app);
void	check_horizont_line(t_app *app);
void	check_vert_left(t_app *app);
void	check_vert_right(t_app *app);
void	check_vert_down_up(t_app *app);
void	check_vert_action(t_app *app);
void	check_vertical_line(t_app *app);
void	draw_mini_rays(t_app *app);
void	draw_rays_3d(t_app *app);

/*prepa_raycasting.c*/
void	prepa_init_ray(t_app *app);
void	fix_fish_eye(t_app *app);
void	which_is_dir(t_app *app);

/*init_1.c*/
void	init_path(t_app *app);
void	init_texture(t_app *app);

/*get_color.c*/
void	opacity(t_app *app, int y, int x, t_rgb *color);
int		color_ceil(t_app *app, int x, int y);
int		color_floor(t_app *app, int x, int y);
int		get_color(t_app *app, int scale, int rx, int i);

#endif