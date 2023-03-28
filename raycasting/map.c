/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:50:09 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 17:57:13 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	init_carre(t_app *app)
{
	int	cote_carre_x;
	int	cote_carre_y;
	int	taille;

	cote_carre_x = RES_X / app->map_x;
	cote_carre_y = RES_Y / app->map_y;
	if (cote_carre_x > cote_carre_y)
		taille = cote_carre_y / 2;
	else
		taille = cote_carre_x / 2;
	return (taille);
}

void	drow_element(t_app *app, int x, int y, int color)
{
	int	i;
	int	j;
	int	taille;

	taille = init_carre(app);
	i = -1;
	while (++i < taille)
	{
		j = -1;
		while (++j < taille)
		{
			if ((j == (taille - 1) || i == (taille - 1)) && taille > 1)
				my_mlx_pixel_put(&(app->img), j + (x * taille),
					i + (y * taille), 0x1A1A1A);
			else
				my_mlx_pixel_put(&(app->img), j + (x * taille),
					i + (y * taille), color);
		}
	}
	if (x == app->map_x - 1 && y == app->map_y - 1)
		disp_player(app, taille);
}

void	draw_map(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	if (app->bool_map == 0)
		return ;
	while (y < app->map_y)
	{
		x = 0;
		while (x < app->map_x)
		{
			if (app->map[y * app->map_x + x] == 1)
				drow_element(app, x, y, 0x00AAAAAA);
			else
				drow_element(app, x, y, 0x00716042);
			x++;
		}
		y++;
	}
}
