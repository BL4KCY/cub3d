#include "cub3d.h"

int	update_minimap(t_info *info)
{
	int	color;

	for (int i = 0; i < info->map.n_row; i++)
	{
		for (int j = 0; j < info->map.n_cols;j++)
		{
			if (info->map.grid[i][j] == '0')
				color = 0x00ffffff;
			else
				color = 0x00000000;
			rect(&info->map.data,
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

void	update_Player_position(t_info *mlx)
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

void	render_rays(t_info *info)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&info->map.data,
		MINIMAP_SCALE_FAC * info->player.x,
		MINIMAP_SCALE_FAC * info->player.y,
		MINIMAP_SCALE_FAC * info->player.ray[i].hit_x,
		MINIMAP_SCALE_FAC * info->player.ray[i].hit_y,
		0x00ff0000);
		i++;
	}
}

void	update_player(t_info *info)
{
	int	x2, y2;

	draw_cir(&info->map.data,
	MINIMAP_SCALE_FAC * info->player.x,
	MINIMAP_SCALE_FAC * info->player.y,
	MINIMAP_SCALE_FAC * info->player.radius,
	0x00ff0000);
	x2 = cos(info->player.rotation_angle) * 40 + info->player.x;
	y2 = sin(info->player.rotation_angle) * 40 + info->player.y;
	draw_line(&info->map.data, info->player.x * MINIMAP_SCALE_FAC, info->player.y * MINIMAP_SCALE_FAC, x2 * MINIMAP_SCALE_FAC, y2 * MINIMAP_SCALE_FAC, 0x00ff0000);
}



int	rendering(t_info *info)
{
	init_img_data(info);
	update_Player_position(info);
	raycasting(info);
	// update_3d(info);
	update_minimap(info);
	update_player(info);
	render_rays(info);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}
