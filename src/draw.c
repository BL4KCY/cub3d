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
