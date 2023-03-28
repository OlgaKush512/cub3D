/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:27:05 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 23:19:55 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*copy_size(char *str, int bpp, int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * ((size + 1) * bpp));
	if (temp == NULL)
		return (NULL);
	while ((i * bpp) < (size * bpp) && str[i * bpp])
	{
		temp[i] = str[i * bpp];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	close_images(t_app *app, int i)
{
	int	j;

	j = 0;
	while (j < i && j < 4)
	{
		mlx_destroy_image(app->mlx, app->txr[j++].img);
	}
}

int	routine(void *data)
{
	t_app		*app;

	app = (t_app *)(data);
	if (app->disp == 0)
		return (0);
	app->img.img = mlx_new_image(app->mlx, app->x, app->y);
	if (app->img.img == NULL)
		destroy_game_data(app, 4);
	app->img.addr = mlx_get_data_addr(app->img.img,
			&app->img.bpp, &app->img.size, &app->img.endian);
	app->image_is_destroyed = 0;
	drow_background(app);
	draw_rays_3d(app);
	draw_map(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
	mlx_destroy_image(app->mlx, app->img.img);
	app->img.img = NULL;
	app->image_is_destroyed = 1;
	app->disp = 0;
	return (0);
}
