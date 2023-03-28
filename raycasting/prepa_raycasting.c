/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepa_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:53:57 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 18:53:59 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	prepa_init_ray(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->ra = app->ray.game_state.pa - DR * (RES_X / 2);
	if (dr->ra < 0)
		dr->ra += 2 * PI;
	if (dr->ra > 2 * PI)
		dr->ra -= 2 * PI;
	dr->x = app->sp.game_state.player_x;
	dr->y = app->sp.game_state.player_y;
	dr->r = 0;
	dr->i = 0;
	dr->mp = 0;
}

void	fix_fish_eye(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->ca = app->ray.game_state.pa - dr->ra;
	if (dr->ca < 0)
	{
		dr->ca += 2 * PI;
	}
	if (dr->ca > 2 * PI)
	{
		dr->ca -= 2 * PI;
	}
	dr->tdist = dr->tdist * cos(dr->ca);
}

void	which_is_dir(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	if (dr->vdist < dr->hdist)
	{
		dr->tdist = dr->vdist;
		dr->rx = dr->vy;
		dr->ry = dr->vy;
		if (dr->ra > PI2 && dr->ra < PI3)
			dr->mod = 2;
		else
			dr->mod = 3;
	}
	if (dr->hdist < dr->vdist)
	{
		dr->tdist = dr->hdist;
		dr->rx = dr->hx;
		dr->ry = dr->hy;
		if (dr->ra > PI)
			dr->mod = 0;
		else
			dr->mod = 1;
	}
}
