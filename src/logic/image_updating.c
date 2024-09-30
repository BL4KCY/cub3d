/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:52:21 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 11:55:22 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_intersec_wall(t_info *info, double i, double j)
{
	int	x_inc;
	int	y_inc;

	x_inc = (int)i / T_SIZE - (int)info->player.x / T_SIZE;
	y_inc = (int)j / T_SIZE - (int)info->player.y / T_SIZE;
	if (1 == abs(x_inc) && 1 == abs(y_inc))
	{
		if (hit_wall(info, info->player.x + x_inc * T_SIZE, info->player.y)
			&& hit_wall(info, info->player.x, info->player.y + y_inc * T_SIZE))
			return (true);
	}
	return (false);
}

void	wall_collision(t_info *info, double new_x, double new_y)
{
	if (!hit_wall(info, new_x, info->player.y))
		info->player.x = new_x;
	if (!hit_wall(info, info->player.x, new_y))
		info->player.y = new_y;
}

void	update_player_position(t_info *info)
{
	double	new_x;
	double	new_y;

	info->player.rotation_angle += info->player.rotation_speed
		* info->player.turn_direction;
	info->player.rotation_angle = normalize_angle(info->player.rotation_angle);
	new_x = info->player.x + (cos(info->player.rotation_angle)
			* info->player.move_speed * info->player.walk_direction)
		+ (cos(info->player.rotation_angle + M_PI_2) * info->player.move_speed
			* info->player.move_rightleft);
	new_y = info->player.y + (sin(info->player.rotation_angle)
			* info->player.move_speed * info->player.walk_direction)
		+ (sin(info->player.rotation_angle + M_PI_2) * info->player.move_speed
			* info->player.move_rightleft);
	if (!hit_wall(info, new_x, new_y)
		&& !check_intersec_wall(info, new_x, new_y))
	{
		info->player.x = new_x;
		info->player.y = new_y;
	}
	else
		wall_collision(info, new_x, new_y);
}
