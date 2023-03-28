/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:45 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 19:20:48 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	reinit_var_input(t_app *app)
{
	t_input	*inp;

	inp = &(app->inp);
	if (app->sp.game_state.delta_x < 0)
		inp->xo = -10;
	else
		inp->xo = 10;
	if (app->sp.game_state.delta_y < 0)
		inp->yo = -10;
	else
		inp->yo = 10;
	inp->posx = app->sp.game_state.player_x / 64.0;
	inp->posx_add_xo = (app->sp.game_state.player_x + inp->xo) / 64.0;
	inp->posx_sub_xo = (app->sp.game_state.player_x - inp->xo) / 64.0;
	inp->posy = app->sp.game_state.player_y / 64.0;
	inp->posy_add_yo = (app->sp.game_state.player_y + inp->yo) / 64.0;
	inp->posy_sub_yo = (app->sp.game_state.player_y - inp->yo) / 64.0;
	inp->posx_add_yo = (app->sp.game_state.player_x + inp->yo) / 64.0;
	inp->posx_sub_yo = (app->sp.game_state.player_x - inp->yo) / 64.0;
	inp->posy_add_xo = (app->sp.game_state.player_y + inp->xo) / 64.0;
	inp->posy_sub_xo = (app->sp.game_state.player_y - inp->xo) / 64.0;
}

int	player_input(int key, void *data)
{
	t_app	*app;
	float	x;
	float	y;

	app = (t_app *)(data);
	x = app->sp.game_state.player_x;
	y = app->sp.game_state.player_y;
	app->sp.game_state.player_old_x = x;
	app->sp.game_state.player_old_y = y;
	return (player_input_body(key, app));
}

int	player_input_body(int key, t_app *app)
{
	reinit_var_input(app);
	if (key == MAP)
	{
		app->disp = 1;
		app->bool_map++;
		app->bool_map %= 2;
		return (1);
	}
	if (key == FL_LEFT || key == FL_RIGHT
		||key == LEFT || key == RIGHT || key == DOWN || key == UP)
	{
		app->disp = 1;
		arrow_input(app, key);
		pos_left_right(app, key);
		pos_down_up(app, key);
	}
	if (key == ESC)
		destroy_game_data(app, 4);
	return (1);
}
