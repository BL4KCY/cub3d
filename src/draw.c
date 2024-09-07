#include "cub3d.h"

void	my_mlx_pixel_set(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	*put_rec(void *mlx, int w, int h, int color)
{
	t_data	data;
	int		x;
	int		y;

	data.img = mlx_new_image(mlx, w, h);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			my_mlx_pixel_set(&data, x, y, color);
			x++;
		}
		y++;
	}
	return (data.img);
}
