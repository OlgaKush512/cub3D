/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:17:39 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 22:16:40 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	ret_int_free(int ret, char *tofree)
{
	free(tofree);
	return (ret);
}

int	good_id(char *str)
{
	if (ft_strcmp(str, "NO") != 0 && ft_strcmp(str, "SO") != 0
		&& ft_strcmp(str, "EA") != 0 && ft_strcmp(str, "WE") != 0
		&& ft_strcmp(str, "F") != 0 && ft_strcmp(str, "C") != 0)
		return (0);
	return (1);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_file(char *str)
{
	int	ret;

	ret = ft_open_file_read(str);
	if (ret < 0)
		return (0);
	else
		close(ret);
	return (1);
}

int	check_colour(char *str)
{
	char	**val;
	int		i;
	int		ret;

	i = 0;
	val = ft_split(str, ',');
	if (tab_len(val) != 3 || str[ft_strlen(str) - 1] == ',')
	{
		ft_free_3dtab(val);
		return (0);
	}
	while (i < 3)
	{
		ret = ft_atoi(val[i]);
		if (ret < 0 || ret > 255 || isonlyset(val[i], "0123456789") == 0)
		{
			ft_free_3dtab(val);
			return (0);
		}
		i++;
	}
	ft_free_3dtab(val);
	return (1);
}
