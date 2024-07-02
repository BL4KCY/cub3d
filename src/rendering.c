#include "cub3d.h"

int	update_map(t_info *mlx)
{
	t_data	data;
	int		color;

	if (mlx->map.data.img)
		mlx_destroy_image(mlx->mlx, mlx->map.data.img);
	data.img =  mlx_new_image(mlx->mlx, mlx->map.n_cols * TILE_SIZE, mlx->map.n_row * TILE_SIZE);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	for (int i = 0; i < mlx->map.n_row; i++)
	{
		for (int j = 0; j < mlx->map.n_cols;j++)
		{
			if (mlx->map.grid[i][j] == '0')
				color = 0x00ffffff;
			else
				color = 0x00000000;
			rect(&data, j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
		}
	}
	mlx->map.data.addr = data.addr;
	mlx->map.data.img = data.img;
	mlx->map.data.bits_per_pixel = data.bits_per_pixel;
	mlx->map.data.line_length = data.line_length;
	mlx->map.data.endian = data.endian;
	return (0);
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

void	update_position(t_info *mlx)
{
	double	new_x;
	double	new_y;

	mlx->player.rotation_angle += mlx->player.rotation_speed * mlx->player.turn_direction;
	mlx->player.rotation_angle = normalize_angle(mlx->player.rotation_angle);
	new_x = mlx->player.x + cos(mlx->player.rotation_angle) * mlx->player.move_speed * mlx->player.walk_direction;
	new_y = mlx->player.y + sin(mlx->player.rotation_angle) * mlx->player.move_speed * mlx->player.walk_direction;
	if (mlx->map.grid[(int)(new_y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '0')
	{
		mlx->player.x = new_x;
		mlx->player.y = new_y;
	}
}

void	render_rays(t_info *mlx, t_ray *ray)
{
	int	i;
	double	x1 = mlx->player.x;
	double	y1 = mlx->player.y;

	i = 0;
	while (i < NUM_RAYS)
	{
		double	x2 = x1 + cos(ray[i].ray_ang) * mlx->player.ray[i].ray_dis;
		double	y2 = y1 + sin(ray[i].ray_ang) * mlx->player.ray[i].ray_dis;
		ray[i].is_ray_right ? puts("right"):puts("left");
		ray[i].is_ray_up ? puts("up"):puts("down");
		draw_line(&mlx->map.data, x1, y1, x2, y2, 0x00ff0000);
		i++;
	}
}
int	update_player(t_info *mlx)
{
	update_position(mlx);
	double	x1 = mlx->player.x;
	double	y1 = mlx->player.y;
	double	x2 = x1 + cos(mlx->player.rotation_angle) * 50;
	double	y2 = y1 + sin(mlx->player.rotation_angle) * 50;
	draw_cir(&mlx->map.data, x1, y1, mlx->player.radius, 0x00ff0000);
	draw_line(&mlx->map.data, x1, y1, x2, y2, 0x00ff0000);
}

int	rendering(t_info *info)
{
	update_map(info);
	update_player(info);
	raycasting(info);
	render_rays(info, info->player.ray);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}
