/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:03:59 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/11 12:06:53 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enqueue(int x, int y, t_queue **front, t_queue **rear)
{
	t_queue	*new_node;

	new_node = (t_queue *)ft_malloc(sizeof(t_queue));
	if (!new_node)
		return ;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (*rear)
	{
		(*rear)->next = new_node;
		*rear = new_node;
	}
	else
	{
		*front = new_node;
		*rear = new_node;
	}
}

void	ft_dequeue(t_queue **front, t_queue **rear)
{
	t_queue	*temp;

	temp = *front;
	if (!temp)
	{
		return ;
	}
	if (*front == *rear)
	{
		*front = NULL;
		*rear = NULL;
	}
	else
	{
		*front = (*front)->next;
	}
}

bool	ft_check_up(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	fill_modified_map_container(char **new_map, char **map, int *i, int *j)
{
	int	hight;
	int	find_longest_line;

	find_longest_line = ft_find_longest_line(map, &hight);
	while (map[*i][*j])
	{
		if (map[*i][*j] == ' ')
			new_map[*i][*j] = 'd';
		else
			new_map[*i][*j] = map[*i][*j];
		(*j)++;
	}
	while (*j < find_longest_line)
	{
		new_map[*i][*j] = 'd';
		(*j)++;
	}
}

char	**fill_modified_map(char **map)
{
	int		find_longest_line;
	char	**new_map;
	int		hight;
	int		i;
	int		j;

	find_longest_line = ft_find_longest_line(map, &hight);
	new_map = (char **)ft_malloc(sizeof(char *) * (hight + 1));
	if (!new_map)
		return (false);
	i = 0;
	while (map[i])
	{
		new_map[i] = (char *)ft_malloc(sizeof(char) * (find_longest_line + 1));
		j = 0;
		fill_modified_map_container(new_map, map, &i, &j);
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
