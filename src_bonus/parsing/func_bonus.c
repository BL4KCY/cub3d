/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:17:08 by mmad              #+#    #+#             */
/*   Updated: 2024/09/25 18:03:50 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_queue(t_queue *front)
{
	t_queue	*current;

	current = front;
	while (current)
	{
		printf("[%d | %d]\n", current->x, current->y);
		current = current->next;
	}
}

bool	ft_to_do_map_bonus(t_list *node, t_condition *game_condition)
{
	t_list	*new_map;
	int		n_direction;

	(void)node;
	new_map = NULL;
	if (!game_condition->map)
		return (false);
	fill_modified_map(game_condition);
	if (ft_check_up(game_condition->map[0]) == false
		|| ft_check_up(game_condition->map[ft_n_columns_2d(game_condition->map)
				- 1]) == false)
		return (false);
	if (!(ft_check_start_end(game_condition->map, &n_direction, 1) == 0
			&& n_direction == 1))
		return (false);
	new_map = ft_add_substrings_to_linked_list(new_map,
			game_condition->pure_map, 0);
	if (breadth_first_search(ft_buffer_to_two_d_array(new_map,
				ft_lstsize(new_map), 0), game_condition)
		&& check_for_dead_ends(game_condition->pure_map))
		return (true);
	return (false);
}

bool	move_on_if_map_valid_bonus(t_condition *condition)
{
	if (condition->substr == NULL)
	{
		printf(RED_W "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	if (ft_grep_to_pars_if('.', condition, ft_to_do_textures)
		&& ft_grep_to_pars_if(',', condition, ft_to_do_c_floor)
		&& ft_grep_to_pars_if('1', condition, ft_to_do_map_bonus))
	{
		printf(GRN_W "[Valid]\n" RESET);
	}
	else
	{
		printf(RED_W "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	return (true);
}
