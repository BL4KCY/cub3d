/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:17:21 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/08 16:50:53 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pars_cub3d.h"

void	ft_find_direction(char **new_map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] == 'N' || new_map[i][j] == 'E'
				|| new_map[i][j] == 'S' || new_map[i][j] == 'W')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	check_for_connectedness(char *str, int *n_directions)
{
	char		*new_str;
	static int	count_directions;
	int			i;

	new_str = ft_strtrim(str, " ");
	i = -1;
	while (new_str[++i])
	{
		if (new_str[i] == 'N' || new_str[i] == 'E' || new_str[i] == 'S'
			|| new_str[i] == 'W')
			count_directions++;
		if (new_str[i] != 'N' && new_str[i] != 'E' && new_str[i] != 'S'
			&& new_str[i] != 'W' && new_str[i] != ' ' && new_str[i] != '0'
			&& new_str[i] != '1')
			return (false);
	}
	*n_directions = count_directions;
	if (new_str[0] == '1' && new_str[ft_strlen(new_str) - 1] == '1')
		return (true);
	else
	{
		if (new_str[0] != '\0')
			return (false);
	}
	return (true);
}

int	ft_check_start_end(char **map, int *n_direction)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_for_connectedness(map[i], n_direction) == false)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_find_longest_line(char **substr, int *hight)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (substr[i])
	{
		if ((int)ft_strlen(substr[i]) > length)
			length = ft_strlen(substr[i]);
		i++;
	}
	*hight = i;
	return (length);
}
