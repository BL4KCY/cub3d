/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:28:24 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/22 04:40:44 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_if_d(char **new_map, t_queue *front, int *x, int *y)
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

bool	breadth_first_search(char **new_map, t_condition *game_condition)
{
	int		x;
	int		y;
	t_queue	*front;
	t_queue	*rear;

	front = NULL;
	rear = NULL;
	ft_find_direction(new_map, &x, &y, game_condition);
	ft_enqueue(x, y, &front, &rear);
	while (front)
	{
		if (ft_check_if_d(new_map, front, &x, &y) == false)
			return (false);
		if (!x || (new_map[x - 1][y] == '0' && (new_map[x - 1][y] = '1')))
			ft_enqueue(x - 1, y, &front, &rear);
		if (new_map[x + 1][y] == '0' && (new_map[x + 1][y] = '1'))
			ft_enqueue(x + 1, y, &front, &rear);
		if (new_map[x][y - 1] == '0' && (new_map[x][y - 1] = '1'))
			ft_enqueue(x, y - 1, &front, &rear);
		if (new_map[x][y + 1] == '0' && (new_map[x][y + 1] = '1'))
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

bool	check_if_wall_can_exist(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[++i])
	{
		j = -1;
		while (new_map[i][++j])
		{
			if (new_map[i][j] == 'B')
			{
				if ((new_map[i - 1] && new_map[i - 1][j] == 'd') || (new_map[i
						+ 1] && new_map[i + 1][j] == 'd') || (new_map[i][j + 1]
						&& new_map[i][j + 1] == '0') || (j > 0 && new_map[i][j
						- 1] && new_map[i][j - 1] == '0'))
				{
					return (false);
				}
			}
		}
	}
	return (true);
}

bool	ft_to_do_map(t_list *node, t_condition *game_condition)
{
	int		n_direction;
	t_list	*new_map;

	new_map = NULL;
	(void)node;
	if (!game_condition->map)
		return (false);
	fill_modified_map(game_condition);
	if (ft_check_up(game_condition->map[0]) == false
		|| ft_check_up(game_condition->map[ft_n_columns_2d(game_condition->map)
				- 1]) == false)
		return (false);
	if (!(ft_check_start_end(game_condition->map, &n_direction, 0) == 0
			&& n_direction == 1))
		return (false);
	new_map = ft_add_substrings_to_linked_list(new_map,
			game_condition->pure_map, 0);
	if (breadth_first_search(ft_buffer_to_two_d_array(new_map,
				ft_lstsize(new_map), 0), game_condition)
		&& check_for_dead_ends(game_condition->pure_map))
		return (true);
	ft_print_substr(game_condition->pure_map);
	return (false);
}
