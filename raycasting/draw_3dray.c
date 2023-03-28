/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3dray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:30:14 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 15:47:08 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ra_new(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->ra += DR;
	if (dr->ra < 0)
		dr->ra += 2 * PI;
	if (dr->ra > 2 * PI)
		dr->ra -= 2 * PI;
}

void	draw_rays_3d_body(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	dr->lineh = ((RES_X) / dr->tdist) * 64;
	dr->saveh = dr->lineh;
	if (dr->lineh > app->y)
		dr->lineh = app->y;
	dr->lineo = app->y / 2 - dr->lineh / 2;
	dr->i = 0;
	while (dr->i < (int)dr->lineh)
	{
		dr->j = 0;
		while (dr->j < 1)
		{
			my_mlx_pixel_put(&(app->img), dr->j + dr->r, dr->i + dr->lineo,
				get_color(app, dr->saveh, dr->rx, dr->i));
			dr->j++;
		}
		dr->i++;
	}
	dr->r++;
	ra_new(app);
}

void	draw_rays_3d(t_app *app)
{
	t_draw	*dr;

	dr = &(app->dr);
	prepa_init_ray(app);
	while (dr->r < RES_X)
	{
		check_horizont_line(app);
		check_vertical_line(app);
		which_is_dir(app);
		fix_fish_eye(app);
		draw_rays_3d_body(app);
	}
}
