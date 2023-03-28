/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:25:32 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/08 10:36:03 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_path(t_app *app)
{
	app->path[0] = app->vars->no_path;
	app->path[1] = app->vars->so_path;
	app->path[2] = app->vars->we_path;
	app->path[3] = app->vars->ea_path;
}

void	init_texture(t_app *app)
{
	int			i;
	t_data		*txr;
	char		**m_path;

	i = 0;
	txr = app->txr;
	m_path = app->path;
	while (i < 4)
	{
		txr[i].img = mlx_xpm_file_to_image(app->mlx, m_path[i],
				&txr[i].w, &txr[i].h);
		if (txr[i].img != NULL)
			txr[i].addr = mlx_get_data_addr(txr[i].img, &(txr[i].bpp),
					&(txr[i].size), &(txr[i].endian));
		else
		{
			write(2, "The texture is not readable\n", 29);
			destroy_game_data(app, i);
		}
		i++;
	}
}
