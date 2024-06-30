#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	rect(t_data *data, int x, int y, int height, int width, int color)
{
	for(int i = y; i < y + height; i++)
	{
		for(int j = x; j < x + width; j++)
		{
			if (i == y + height - 1 || j == x + width - 1)
				my_mlx_pixel_put(data, j, i, 0x00000000);
			else my_mlx_pixel_put(data, j, i, color);
		}
	}
}

void	draw_cir(t_data *data, int x, int y, int radius, int color)
{
	for (int i = y - radius; i < y + radius; i++)
	{
		for (int j = x - radius; j < x + radius; j++)
		{
			if (sqrt(pow(j - x, 2) + pow(i - y, 2)) <= radius)
				my_mlx_pixel_put(data, j, i, color);
		}
	}
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	float X = x1;
	float Y = y1;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, X, Y, color);
		X += Xinc;
		Y += Yinc;
	}
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
