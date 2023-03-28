/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:25:46 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/02/07 17:34:30 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	ret_int_free_3d(char **str, int ret)
{
	ft_free_3dtab(str);
	return (ret);
}

int	second_args(char *str, char *id)
{
	int	ret;

	ret = 1;
	if (ft_strlen(id) == 1)
		ret = check_colour(str);
	else
		ret = check_file(str);
	return (ret);
}

int	isonlyset(char *str, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			return (0);
		i++;
	}
	return (1);
}

int	two_nums(char *s1, const char *s2)
{
	char	last;
	char	first;

	if (s1[0] == 0)
		return (0);
	last = s1[ft_strlen(s1) - 1];
	first = s2[0];
	if (ft_isdigit(first) && ft_isdigit(last))
	{
		free(s1);
		return (1);
	}
	if (first == ',' && last == ',')
	{
		free(s1);
		return (1);
	}
	return (0);
}

int	isonlyspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'
			|| str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
