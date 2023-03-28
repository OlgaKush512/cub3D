/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <okushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:11:43 by okushnir          #+#    #+#             */
/*   Updated: 2022/02/07 19:11:45 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	isinset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	add_starting_angle(t_app *app, char c, int j, int i)
{
	app->starting_x = j;
	app->starting_y = i;
	if (c == 'N')
		app->starting_angle = PI / -2;
	else if (c == 'S')
		app->starting_angle = PI / 2;
	else if (c == 'W')
		app->starting_angle = PI;
	else if (c == 'E')
		app->starting_angle = 0;
}

int	*fill_map(int size, int longest, char **map, t_app *app)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < longest)
		{
			if (j < ft_strlen(map[i]) && map[i][j] != ' ')
				tab[i * longest + j] = map[i][j] - 48;
			else
				tab[i * longest + j] = -1;
			if (j < ft_strlen(map[i]) && isinset(map[i][j], "NSWE"))
			{
				add_starting_angle(app, map[i][j], j, i);
				tab[i * longest + j] = 0;
			}
		}
	}
	return (tab);
}

void	init_map(t_app *app, char **map)
{
	int	i;
	int	longest;

	i = 1;
	longest = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > longest)
			longest = ft_strlen(map[i]);
		i++;
	}
	app->map = fill_map(longest * i, longest, map, app);
	if (app->map == NULL)
		destroy_game_data(app, -1);
	ft_free_3dtab(map);
	app->map_x = longest;
	app->map_y = i;
}
