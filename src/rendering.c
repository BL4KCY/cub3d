#include "cub3d.h"

int	update_map(t_info *mlx)
{
	int	color;

	for (int i = 0; i < mlx->map.n_row; i++)
	{
		for (int j = 0; j < mlx->map.n_cols;j++)
		{
			if (mlx->map.grid[i][j] == '0')
				color = 0x00ffffff;
			else
				color = 0x00000000;
			rect(&mlx->map.data,
			MINIMAP_SCALE_FAC * j * TILE_SIZE,
			MINIMAP_SCALE_FAC * i * TILE_SIZE,
			MINIMAP_SCALE_FAC * TILE_SIZE,
			MINIMAP_SCALE_FAC * TILE_SIZE,
			color);
		}
	}
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

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&mlx->map.data,
		MINIMAP_SCALE_FAC * mlx->player.x,
		MINIMAP_SCALE_FAC * mlx->player.y,
		MINIMAP_SCALE_FAC * mlx->player.ray[i].hit_x,
		MINIMAP_SCALE_FAC * mlx->player.ray[i].hit_y,
		0x00ff0000);
		i++;
	}
}
int	update_player(t_info *mlx)
{
	update_position(mlx);
}

void	set_wall_strip_texture(t_info *info,int id, int top, int btm)
{
	int	offset_x;
	int	offset_y;
	int	y;
	int	color;

	if (info->player.ray[id].is_hor)
		offset_x = (int)info->player.ray[id].hit_x % TILE_SIZE;
	else
		offset_x = (int)info->player.ray[id].hit_y %  TILE_SIZE;
	y = top;
	if (y < 0)
		y = 0;
	while (y < btm)
	{
		offset_y = (y - top) * (info->tex.ea_dem.y / info->player.ray[id].strip_height);
		// printf("offset_y: %d,\toffset_x: %d\n", offset_y, offset_x);
		color = my_mlx_pixel_get(&info->tex.ea_data, abs(offset_x), offset_y);
		my_mlx_pixel_set(&info->map.data, id, y, color);
		y++;
	}
}

void	update_3d(t_info *info)
{
	t_data	data;
	int		color;
	int		strip_top_y;
	int		strip_btm_y;

	if (info->map.data.img)
		mlx_destroy_image(info->mlx, info->map.data.img);
	data.img =  mlx_new_image(info->mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
								&data.line_length, &data.endian);
	info->map.data.addr = data.addr;
	info->map.data.img = data.img;
	info->map.data.bits_per_pixel = data.bits_per_pixel;
	info->map.data.line_length = data.line_length;
	info->map.data.endian = data.endian;
	// set ceiling texture
	rect(&data, 0, 0, HEIGHT / 2, WIDTH, CCOLOR);
	// set floor texture
	rect(&data, 0, HEIGHT / 2, HEIGHT, WIDTH, FCOLOR);
	// set wall strip texture
	for (int i = 0; i < NUM_RAYS; i++)
	{
		if (info->player.ray[i].is_hor)
			color = 0x00ee5900;
		else
			color = 0x00ab4000;

		rect(&info->map.data,
		i * STRIP_WIDTH,
		(HEIGHT / 2) - (info->player.ray[i].strip_height / 2),
		info->player.ray[i].strip_height,
		STRIP_WIDTH,
		color);
	}
}
int	rendering(t_info *info)
{
	static int	i;

	update_player(info);;
	raycasting(info);
	update_3d(info);
	update_map(info);
	render_rays(info, info->player.ray);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	i++;
	return (0);
}
