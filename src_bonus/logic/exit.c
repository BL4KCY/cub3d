/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:19:08 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 11:25:43 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_info *info)
{
	int		weapon_id;
	int		i;

	i = -1;
	weapon_id = -1;
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_image(info->mlx, info->map.data.img);
	while (++i < 5)
		mlx_destroy_image(info->mlx, info->tex.img[i].data.img);
	while (++weapon_id < N_WEAPONS)
	{
		i = -1;
		while (++i < info->weapon[weapon_id].n_frames)
			mlx_destroy_image(info->mlx,
				info->weapon[weapon_id].img[i].data.img);
	}
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	ft_hunt_leak();
	exit(0);
}
