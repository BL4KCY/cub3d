/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map_holder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 04:07:23 by mmad              #+#    #+#             */
/*   Updated: 2024/09/22 04:24:55 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	move_on_if_map_valid(t_condition *condition)
{
	if (condition->substr == NULL)
	{
		printf(RED_W "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	if (ft_grep_to_pars_if('.', condition, ft_to_do_textures)
		&& ft_grep_to_pars_if(',', condition, ft_to_do_c_floor)
		&& ft_grep_to_pars_if('1', condition, ft_to_do_map))
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
