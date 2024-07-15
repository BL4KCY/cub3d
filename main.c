#include <mlx.h>

#include <stdio.h>
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_set(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	void	*mlx  = mlx_init();
	void	*win  = mlx_new_window(mlx, 500, 500, "h");

	t_data  data;

	data.img = mlx_new_image(mlx, 20, 1);

	mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	printf("bit_per_pixel: %d, line_lenght: %d\n", data.bits_per_pixel, data.line_length);

	mlx_put_image_to_window(mlx, win, data.img, 50, 50);

	mlx_loop(mlx);
}
