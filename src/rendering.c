#include "cub3d.h"

int	update_minimap(t_info *info)
{
	int	color;
	int	x;
	int	y;

	x = info->player.x <= 200 ? 0 : info->player.x - 200;
	y = info->player.y <= 200 ? 0 : info->player.y - 200;
	for (int i = 0; i < info->map.n_row; i++)
	{
		for (int j = 0; j < info->map.n_cols;j++)
		{
			if (info->map.grid[i][j] == '0')
				color = WHITE;
			else
				color = BROWN;
			rect_cir(&info->map.data,
			MINIMAP_SCALE_FAC * j * TILE_SIZE - MINIMAP_SCALE_FAC * x,
			MINIMAP_SCALE_FAC * i * TILE_SIZE - MINIMAP_SCALE_FAC * y,
			MINIMAP_SCALE_FAC * TILE_SIZE,
			MINIMAP_SCALE_FAC * TILE_SIZE,
			MINIMAP_SCALE_FAC * 200,
			MINIMAP_SCALE_FAC * 200,
			MINIMAP_SCALE_FAC * 200,
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
	new_x = mlx->player.x + (cos(mlx->player.rotation_angle) * mlx->player.move_speed * mlx->player.walk_direction)
						  + (mlx->player.move_rightleft * mlx->player.move_speed);
	new_y = mlx->player.y + (sin(mlx->player.rotation_angle) * mlx->player.move_speed * mlx->player.walk_direction)
						  + (mlx->player.move_updown * mlx->player.move_speed);
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
		MINIMAP_SCALE_FAC * 200,
		MINIMAP_SCALE_FAC * 200,
		MINIMAP_SCALE_FAC * info->player.ray[i].hit_x,
		MINIMAP_SCALE_FAC * info->player.ray[i].hit_y,
		0x00ff0000);
		i++;
	}
}

void	update_player(t_info *info)
{
	int	x2, y2;
	int	limit_x, limit_y;
	int	player_x, player_y;

	player_x = (info->player.x < 200 ? info->player.x : 200);
	player_y = (info->player.y < 200 ? info->player.y : 200);
	draw_cir(&info->map.data,
	MINIMAP_SCALE_FAC * player_x,
	MINIMAP_SCALE_FAC * player_y,
	MINIMAP_SCALE_FAC * info->player.radius,
	BLUE);
	limit_x = 200;//info->player.x <= 200 ? 200 : info->player.x;
	limit_y = 200;//info->player.y <= 200 ? 200 : info->player.y;
	draw_empty_cir(&info->map.data, MINIMAP_SCALE_FAC * limit_x, MINIMAP_SCALE_FAC * limit_y, MINIMAP_SCALE_FAC * 200, BLUE);
	x2 = cos(info->player.rotation_angle) * 40 + player_x;
	y2 = sin(info->player.rotation_angle) * 40 + player_y;
	draw_line(&info->map.data, player_x * MINIMAP_SCALE_FAC, player_y * MINIMAP_SCALE_FAC, x2 * MINIMAP_SCALE_FAC, y2 * MINIMAP_SCALE_FAC, BLUE);
}



int	rendering(t_info *info)
{
	init_img_data(info);
	update_Player_position(info);
	raycasting(info);
	// update_3d(info);
	update_minimap(info);
	update_player(info);
	// render_rays(info);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}
