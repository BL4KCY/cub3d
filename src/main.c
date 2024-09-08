/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/07 19:47:43 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*get_info(void)
{
	static t_info	info;

	return (&info);
}

int	main(void)
{
	t_info	*info;

	info = (t_info *)get_info();
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_hook(info->win, ON_DESTROY, KEYPRESSMASK, ft_exit, info);
	mlx_hook(info->win, ON_KEYDOWN, KEYPRESSMASK, keypress, info);
	mlx_hook(info->win, ON_KEYUP, KEYRELEASEMASK, keyrelease, info);
	init_map(info);
	init_player(info);
	// init_texture(info);
	mlx_loop_hook(info->mlx, rendering, info);
	mlx_loop(info->mlx);
}
