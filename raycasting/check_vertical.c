/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:52:35 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 18:52:39 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_vert_left(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->rx = (((int)dr->x >> 6) << 6) - 0.0005;
	dr->ry = (dr->x - dr->rx) * dr->n_tan + dr->y;
	dr->xo = -64;
	dr->yo = -1 * dr->xo * dr->n_tan;
}

void	check_vert_right(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->rx = (((int)dr->x >> 6) << 6) + 64;
	dr->ry = (dr->x - dr->rx) * dr->n_tan + dr->y;
	dr->xo = 64;
	dr->yo = -1 * dr->xo * dr->n_tan;
}

void	check_vert_down_up(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->rx = dr->x;
	dr->ry = dr->y;
	dr->dof = app->map_x;
}

void	check_vert_action(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->mp = 0;
	dr->mx = (int)(dr->rx) >> 6;
	dr->my = (int)(dr->ry) >> 6;
	dr->mp = dr->my * app->map_x + dr->mx;
	if (dr->mp > 0 && dr->mp < (app->map_x * app->map_y)
		&& (app->map[dr->mp] == 1))
		dr->dof = app->map_x;
	else
	{
		dr->rx += dr->xo;
		dr->ry += dr->yo;
		dr->dof += 1;
		dr->mp = 100;
	}
}

void	check_vertical_line(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->dof = 0;
	dr->n_tan = -1 * tan(dr->ra);
	if (dr->ra > PI2 && dr->ra < PI3)
		check_vert_left(app);
	if (dr->ra < PI2 || dr->ra > PI3)
		check_vert_right(app);
	if ((dr->ra == 0) || (dr->ra == PI))
		check_vert_down_up(app);
	while (dr->dof < app->map_x)
		check_vert_action(app);
	dr->vx = dr->rx;
	dr->vy = dr->ry;
	dr->vdist = sqrt(pow(dr->rx - dr->x, 2) + (pow(dr->ry - dr->y, 2)));
}
