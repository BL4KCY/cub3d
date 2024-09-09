/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:28:24 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/09 15:44:55 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pars_cub3d.h"

bool	ft_check_if_d(char **new_map, t_data *front, int *x, int *y)
{
	*x = front->x;
	*y = front->y;
	if (!*x || new_map[*x - 1][*y] == 'd' || new_map[*x][*y - 1] == 'd'
		|| new_map[*x][*y + 1] == 'd' || new_map[*x + 1][*y] == 'd')
	{
		return (false);
	}
	return (true);
}

bool	breadth_first_search(char **new_map)
{
	t_data	*front;
	t_data	*rear;
	int		x;
	int		y;

	front = NULL;
	rear = NULL;
	ft_find_direction(new_map, &x, &y);
	ft_enqueue(x, y, &front, &rear);
	while (front)
	{
		if (ft_check_if_d(new_map, front, &x, &y) == false)
			return (false);
		if (!x || new_map[x - 1][y] == '0')
			ft_enqueue(x - 1, y, &front, &rear);
		if (new_map[x + 1][y] == '0')
			ft_enqueue(x + 1, y, &front, &rear);
		if (new_map[x][y - 1] == '0')
			ft_enqueue(x, y - 1, &front, &rear);
		if (new_map[x][y + 1] == '0')
			ft_enqueue(x, y + 1, &front, &rear);
		new_map[x][y] = '1';
		ft_dequeue(&front, &rear);
	}
	return (true);
}

bool	check_for_dead_ends(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[++i])
	{
		j = -1;
		while (new_map[i][++j])
		{
			if (new_map[i][j] == 'd')
			{
				if ((new_map[i - 1] && new_map[i - 1][j] == '0') || (new_map[i
						+ 1] && new_map[i + 1][j] == '0') || (new_map[i][j + 1]
						&& new_map[i][j + 1] == '0') || (j > 0 && new_map[i][j
						- 1] && new_map[i][j - 1] == '0'))
					return (false);
			}
			if (new_map[i][j] == '0')
			{
				if ((new_map[i - 1] && new_map[i - 1][j] == 'd'))
					return (false);
			}
		}
	}
	return (true);
}

int	ft_n_columns_2d(char **substr)
{
	int	i;

	i = 0;
	while (substr[i])
		i++;
	return (i);
}

bool	ft_to_do_map(t_list *node, t_condition *game_condition)
{
	char	**new_map;
	int		n_direction;
	int		flag_second_check;
	int		flag_bfs_true;

	(void)node;
	if (!game_condition->map)
		return (false);
	flag_bfs_true = 0;
	flag_second_check = 0;
	if (ft_check_up(game_condition->map[0]) == false
		|| ft_check_up(game_condition->map[ft_n_columns_2d(game_condition->map)
				- 1]) == false)
		return (false);
	if (!(ft_check_start_end(game_condition->map, &n_direction) == 0
			&& n_direction == 1))
		return (false);
	new_map = fill_modified_map(game_condition->map);
	if (breadth_first_search(new_map) == true)
		flag_bfs_true = 1;
	if (check_for_dead_ends(new_map) == true)
		flag_second_check = 1;
	if (flag_bfs_true == 1 && flag_second_check == 1)
		return (true);
	return (false);
}
