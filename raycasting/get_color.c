/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:43:26 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 15:44:55 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color_ceil(t_app *app, int x, int y)
{
	t_rgb	color;
	int		new;

	(void)x;
	(void)y;
	new = 0;
	color.red = app->ceil_col.red;
	color.green = app->ceil_col.green;
	color.blue = app->ceil_col.blue;
	new |= color.red << 16;
	new |= color.green << 8;
	new |= color.blue;
	return (new);
}

int	color_floor(t_app *app, int x, int y)
{
	t_rgb	color;
	int		new;

	(void)x;
	(void)y;
	new = 0;
	color.red = app->flo_col.red;
	color.green = app->flo_col.green;
	color.blue = app->flo_col.blue;
	new |= color.red << 16;
	new |= color.green << 8;
	new |= color.blue;
	return (new);
}

int	get_color(t_app *app, int scale, int rx, int i)
{
	int				bpp;
	t_rgb			color;
	unsigned int	ind;
	int				new;
	int				x;

	new = 0;
	ind = app->dr.mod;
	if (scale > RES_Y)
		i = i + (scale / 2 - RES_Y / 2);
	i = i * app->txr[ind].h / scale;
	x = (rx * app->txr[ind].w / 64) % app->txr[ind].w;
	bpp = app->txr[ind].bpp / 8;
	color.blue = app->txr[ind].addr[i * app->txr[ind].size + x * bpp];
	color.green = app->txr[ind].addr[i * app->txr[ind].size + x * bpp + 1];
	color.red = app->txr[ind].addr[i * app->txr[ind].size + x * bpp + 2];
	color.op = app->txr[ind].addr[i * app->txr[ind].size + x * bpp + 3];
	new |= color.red << 16;
	new |= color.green << 8;
	new |= color.blue;
	return (new);
}
