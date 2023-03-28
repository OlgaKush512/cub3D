/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:55 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 19:20:58 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	arrow_left(t_app *app)
{
	app->sp.game_state.pa -= 0.1;
	app->ray.game_state.pa -= 0.1;
	if (app->sp.game_state.pa < 0)
	{
		app->sp.game_state.pa += 2.0 * PI;
		app->ray.game_state.pa += 2.0 * PI;
	}
	app->sp.game_state.delta_x = cosf(app->sp.game_state.pa) * 5;
	app->sp.game_state.delta_y = sinf(app->sp.game_state.pa) * 5;
}

void	arrow_right(t_app *app)
{
	app->sp.game_state.pa += 0.1;
	app->ray.game_state.pa += 0.1;
	if (app->sp.game_state.pa > 2.0 * PI)
	{
		app->sp.game_state.pa -= 2.0 * PI;
		app->ray.game_state.pa -= 2.0 * PI;
	}
	app->sp.game_state.delta_x = cosf(app->sp.game_state.pa) * 5;
	app->sp.game_state.delta_y = sinf(app->sp.game_state.pa) * 5;
}

void	arrow_input(t_app *app, int key)
{
	if (key == FL_LEFT)
		arrow_left(app);
	else if (key == FL_RIGHT)
		arrow_right(app);
}

void	pos_left_right(t_app *app, int key)
{
	t_input		*inp;

	inp = &(app->inp);
	if (key == LEFT)
	{
		if (app->map[inp->posy * app->map_x + inp->posx_add_yo] != 1)
			app->sp.game_state.player_x += (app->sp.game_state.delta_y) / 1;
		if (app->map[inp->posy_sub_xo * app->map_x + inp->posx] != 1)
			app->sp.game_state.player_y -= (app->sp.game_state.delta_x) / 1;
	}
	else if (key == RIGHT)
	{
		if (app->map[inp->posy * app->map_x + inp->posx_sub_yo] != 1)
			app->sp.game_state.player_x -= (app->sp.game_state.delta_y) / 1;
		if (app->map[inp->posy_add_xo * app->map_x + inp->posx] != 1)
			app->sp.game_state.player_y += (app->sp.game_state.delta_x) / 1;
	}
}

void	pos_down_up(t_app *app, int key)
{
	t_input		*inp;

	inp = &(app->inp);
	if (key == DOWN)
	{
		if (app->map[inp->posy * app->map_x + inp->posx_sub_xo] != 1)
			app->sp.game_state.player_x -= (app->sp.game_state.delta_x) / 1;
		if (app->map[inp->posy_sub_yo * app->map_x + inp->posx] != 1)
			app->sp.game_state.player_y -= (app->sp.game_state.delta_y) / 1;
	}
	else if (key == UP)
	{
		if (app->map[inp->posy * app->map_x + inp->posx_add_xo] != 1)
			app->sp.game_state.player_x += (app->sp.game_state.delta_x) / 1;
		if (app->map[inp->posy_add_yo * app->map_x + inp->posx] != 1)
			app->sp.game_state.player_y += (app->sp.game_state.delta_y) / 1;
	}
}
