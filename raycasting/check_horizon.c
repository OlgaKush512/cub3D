/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:53:17 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 18:53:24 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_hor_down(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->ry = (((int)dr->y >> 6) << 6) - 0.0005;
	dr->rx = (dr->y - dr->ry) * dr->a_tan + dr->x;
	dr->yo = -64;
	dr->xo = (-1 * dr->yo) * dr->a_tan;
}

void	check_hor_up(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->ry = (((int)dr->y >> 6) << 6) + 64;
	dr->rx = (dr->y - dr->ry) * dr->a_tan + dr->x;
	dr->yo = 64;
	dr->xo = (-1 * dr->yo) * dr->a_tan;
}

void	check_hor_left_right(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->rx = dr->x;
	dr->ry = dr->y;
	dr->dof = app->map_y;
}

void	check_hor_action(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->mp = 0;
	dr->mx = (int)(dr->rx) >> 6;
	dr->my = (int)(dr->ry) >> 6;
	dr->mp = dr->my * app->map_x + dr->mx;
	if (dr->mp > 0 && dr->mp < (app->map_x * app->map_y)
		&& (app->map[dr->mp] == 1))
	{
		dr->dof = app->map_y;
	}
	else
	{
		dr->rx += dr->xo;
		dr->ry += dr->yo;
		dr->dof += 1;
		dr->mp = 100;
	}
}

void	check_horizont_line(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->dof = 0;
	dr->mp = 0;
	dr->a_tan = -1 / tan(dr->ra);
	if (dr->ra > PI)
		check_hor_down(app);
	if (dr->ra < PI)
		check_hor_up(app);
	if ((dr->ra == 0) || (dr->ra == PI))
		check_hor_left_right(app);
	while (dr->dof < app->map_y)
		check_hor_action(app);
	dr->hx = dr->rx;
	dr->hy = dr->ry;
	dr->hdist = sqrt(pow(dr->rx - dr->x, 2) + (pow(dr->ry - dr->y, 2)));
}
