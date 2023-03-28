/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:16 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 18:59:18 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	draw_line(t_app *app, int t)
{
	int		i;
	float	x;
	float	y;

	x = app->sp.game_state.player_x / 64;
	y = app->sp.game_state.player_y / 64;
	i = 0;
	while (i < t / 3)
	{
		my_mlx_pixel_put(&(app->img), x * t + (i * cos(app->ray.game_state.pa)),
			y * t + (i * sin(app->ray.game_state.pa)), 0x003A51B0);
		i++;
	}
}

int	check_size_map(int taille, t_app *app)
{
	if (taille < 1)
	{
		write(2, "Map is too big, can't be displayed\n", 36);
		app->bool_map = 0;
		return (1);
	}
	return (0);
}

void	disp_player(t_app *app, int taille)
{
	int		x;
	int		y;
	float	abs_x;
	float	abs_y;
	float	res;

	if (check_size_map(taille, app))
		return ;
	abs_x = app->sp.game_state.player_x / 64;
	abs_y = app->sp.game_state.player_y / 64;
	res = taille / 5;
	if (res < 2)
		res = 2;
	x = -1;
	while (++x < res)
	{
		y = -1;
		while (++y < res)
			my_mlx_pixel_put(&(app->img), abs_x * taille + (x - res / 2),
				abs_y * taille + (y - res / 2), 0xFF0000);
	}
	draw_line(app, taille);
}
