/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:03:58 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/08 11:23:07 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	check_map(char *str, int fd)
{
	int	ret;

	if (str[0] != '1')
		return (1);
	if (isonlyset(str, " 10NSWE") == 0)
		return (0);
	while (1)
	{
		ret = get_next_line(fd, &str);
		if (ret > 0)
		{
			if (isonlyset(str, " 10NSWE") == 0)
				return (ret_int_free(0, str));
			free(str);
		}
		else
			break ;
	}
	if (isonlyset(str, " 10NSWE") == 0)
		return (ret_int_free(0, str));
	return (ret_int_free(1, str));
}

char	*get_colours(char **args)
{
	int		i;
	char	*temp;

	temp = ft_strdup("");
	if (temp == NULL)
		return (NULL);
	i = 1;
	while (args[i])
	{
		if (two_nums(temp, args[i]) == 1)
		{
			while (args[i])
				free(args[i++]);
			return (NULL);
		}
		temp = ft_strjoin(temp, args[i]);
		free(args[i]);
		args[i] = NULL;
		if (temp == NULL)
			return (NULL);
		i++;
	}
	return (temp);
}

int	parse_line(char *str, int fd)
{
	char		**args;
	static int	i = 0;

	if (str[0] == 0)
		return (1);
	if (isonlyspace(str) == 1 || isgoodline(str) == 0)
		return (0);
	if (i == 6)
		return (check_map(str, fd));
	args = ft_split(str, ' ');
	if (!args)
		return (1);
	if ((args[0][0] == 'C' || args[0][0] == 'F') && tab_len(args) >= 2)
	{
		args[1] = get_colours(args);
		args[2] = NULL;
	}
	if (args[1] == NULL || tab_len(args) != 2)
		return (ret_int_free_3d(args, 0));
	if (good_id(args[0]) == 0 || second_args(args[1], args[0]) == 0)
		return (ret_int_free_3d(args, 0));
	ft_free_3dtab(args);
	i++;
	return (1);
}

int	check_lines(int fd)
{
	char	*str;
	int		counter;
	int		ret;

	counter = 1;
	while (1)
	{
		ret = get_next_line(fd, &str);
		if (ret > 0)
		{		
			if (parse_line(str, fd) == 0)
				return (ret_int_free(counter, str));
			free(str);
		}
		else
			break ;
		counter++;
	}			
	if (parse_line(str, fd) == 0)
		return (ret_int_free(counter, str));
	free(str);
	return (-1);
}

int	check_input(char *file)
{
	int	fd;
	int	err;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open this file\n", 2);
		return (0);
	}
	err = check_lines(fd);
	close(fd);
	if (err != -1)
	{
		ft_putstr_fd("Error\nWrong scene configuration at line ", 2);
		ft_putnbr_fd(err, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
