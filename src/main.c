/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/07/07 16:31:57 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*get_info(void)
{
	static t_info	mlx;
	return (&mlx);
}

int	main(void)
{
	t_info	*mlx;

	mlx = (t_info *)get_info();
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_hook(mlx->win, ON_DESTROY, KEYPRESSMASK, ft_exit, mlx);
	mlx_hook(mlx->win, ON_KEYDOWN, KEYPRESSMASK, keypress, mlx);
	mlx_hook(mlx->win, ON_KEYUP, KEYRELEASEMASK, keyrelease, mlx);
	init_map(mlx);
	init_player(mlx);
	init_texture(mlx);
	mlx_loop_hook(mlx->mlx, rendering, mlx);
	mlx_loop(mlx->mlx);
}
