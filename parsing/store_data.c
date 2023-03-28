/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:38:47 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 17:15:08 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

void	init_data(t_vars **data)
{
	*data = malloc(sizeof(t_vars));
	if (*data == NULL)
		return ;
	ft_bzero(*data, sizeof(t_vars));
	(*data)->ceiling_col[0] = -1;
	(*data)->ceiling_col[1] = -1;
	(*data)->ceiling_col[2] = -1;
	(*data)->floor_col[0] = -1;
	(*data)->floor_col[1] = -1;
	(*data)->floor_col[2] = -1;
}

t_vars	*get_data(char *str)
{
	t_vars	*data;
	int		fd;

	data = NULL;
	fd = ft_open_file_read(str);
	if (fd < 0)
		exit (bad_fd());
	init_data(&data);
	if (data == NULL)
	{
		close(fd);
		return (NULL);
	}
	get_values(data, fd);
	get_map(data, fd);
	close(fd);
	check_data(data);
	return (data);
}
