/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:11:14 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 22:51:39 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_paths(t_app *app)
{
	free(app->path[0]);
	free(app->path[1]);
	free(app->path[2]);
	free(app->path[3]);
}

int	destroy_game_data(void *data, int i)
{
	t_app		*app;

	app = (t_app *)data;
	close_images(app, i);
	if (i != -1)
		free(app->map);
	if (i == -1)
		ft_free_3dtab(app->vars->map);
	free(app->vars);
	free_paths(app);
	if (app->image_is_destroyed == 0)
		mlx_destroy_image(app->mlx, app->img.img);
	if ((i != -1) && app->win)
	{
		mlx_clear_window(app->mlx, app->win);
		mlx_destroy_window(app->mlx, app->win);
	}
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
}
