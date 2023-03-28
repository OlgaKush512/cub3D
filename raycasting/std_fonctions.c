/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:54:10 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 23:17:07 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_sprite(t_app *app)
{
	app->sp.game_state.player_x = app->starting_x * 64 + 32;
	app->sp.game_state.player_y = app->starting_y * 64 + 32;
	app->sp.game_state.player_old_x = 0;
	app->sp.game_state.player_old_y = 0;
	app->sp.game_state.pa = app->starting_angle;
	app->sp.game_state.delta_x = cosf(app->sp.game_state.pa) * 5;
	app->sp.game_state.delta_y = sinf(app->sp.game_state.pa) * 5;
	app->ray.game_state.pa = app->starting_angle ;
}

void	drow_background(t_app *app)
{
	int	i;
	int	y;
	int	color;

	i = 0;
	while (i < RES_X)
	{
		y = 0;
		while (y < RES_Y)
		{
			if (y < RES_Y / 2)
				color = color_ceil(app, i, y);
			else
				color = color_floor(app, i, y);
			my_mlx_pixel_put(&(app->img), i, y, color);
			y++;
		}
		i++;
	}
}

void	init_colors(t_app *app)
{
	app->ceil_col.red = app->vars->ceiling_col[0];
	app->ceil_col.green = app->vars->ceiling_col[1];
	app->ceil_col.blue = app->vars->ceiling_col[2];
	app->flo_col.red = app->vars->floor_col[0];
	app->flo_col.green = app->vars->floor_col[1];
	app->flo_col.blue = app->vars->floor_col[2];
}

void	init_app(t_app *app, char *title, int w, int h)
{	
	app->mlx = mlx_init();
	app->win = NULL;
	if (app->mlx == NULL)
	{
		free_data(app->vars);
		exit(1);
	}
	app->disp = 1;
	app->image_is_destroyed = 1;
	init_path(app);
	init_map(app, app->vars->map);
	init_texture(app);
	app->x = w;
	app->y = h;
	app->bool_map = 0;
	app->win = mlx_new_window(app->mlx, w, h, title);
	if (app->win == NULL)
		destroy_game_data(app, 4);
	init_sprite(app);
	init_colors(app);
}
