/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/06/29 20:24:40 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_info	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3d");
	mlx.img = put_rec(mlx.mlx, WIDTH, HEIGHT, BCOLOR);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, ON_DESTROY, KEYPRESSMASK, ft_exit, &mlx);
	mlx_hook(mlx.win, ON_KEYDOWN, KEYPRESSMASK, keyboard, &mlx);
	mlx_loop_hook(mlx.mlx, rendering, &mlx);
	mlx_loop(mlx.mlx);
}
