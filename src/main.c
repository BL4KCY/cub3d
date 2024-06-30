/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/06/30 14:53:45 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*data(void)
{
	static t_info	mlx;
	return (&mlx);
}

int	main(void)
{
	t_info	*mlx;

	mlx = (t_info *)data();
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx->img = put_rec(mlx->mlx, WIDTH, HEIGHT, BCOLOR);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, ON_DESTROY, KEYPRESSMASK, ft_exit, mlx);
	mlx_hook(mlx->win, ON_KEYDOWN, KEYPRESSMASK, keypress, mlx);
	mlx_hook(mlx->win, ON_KEYUP, KEYRELEASEMASK, keyrelease, mlx);
	init_map(mlx);
	init_player(mlx);
	mlx_loop_hook(mlx->mlx, rendering, mlx);
	mlx_loop(mlx->mlx);
}
