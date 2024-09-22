/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:01:26 by mmad              #+#    #+#             */
/*   Updated: 2024/09/22 04:26:59 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_n_columns_2d(char **substr)
{
	int	i;

	i = 0;
	while (substr[i])
		i++;
	return (i);
}

// void	ft_print_queue(t_queue *front)
// {
// t_queue	*current;

// 	current = front;
// 	while (current)
// 	{
// 		printf("[%d | %d]\n", current->x, current->y);
// 		current = current->next;
// 	}
// }
