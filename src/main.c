/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/06/29 19:06:44 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	*put_rec(void *mlx, int w, int h, int color)
{
	t_data	data;

	data.img = mlx_new_image(mlx, w, h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	for (int y = 0; y < h;y++)
		for (int x = 0; x < w; x++)
			my_mlx_pixel_put(&data, x, y, color);
	return (data.img);
}

int	max(int a, int b)
{
	return (a > b ? a : b);
}
int	min(int a, int b)
{
	return (a < b ? a : b);
}

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
