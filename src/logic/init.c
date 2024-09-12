#include "cub3d.h"


void	init_map(t_info *info, t_condition *condition)
{
	info->map.grid = condition->pure_map;
	ft_print_substr(condition->pure_map);
	info->map.n_row = condition->height_of_map;
	info->map.n_cols = condition->width_of_map;
	printf("x_player: %d, y_player: %d\n", condition->x_player, condition->y_player);
	info->map.grid[condition->y_player][condition->x_player] = '0'; 
	info->width = info->map.n_cols * T_SIZE;
	info->height = info->map.n_row * T_SIZE;
	info->map.data.img = NULL;
}

// double	get_red

void	init_player(t_info *info, t_condition *condition)
{
	(void)condition;
	printf("%d %d\n", condition->x_player, condition->y_player);
	info->player.x = (condition->x_player * T_SIZE) + (T_SIZE / 2);
	info->player.y = (condition->y_player * T_SIZE) + (T_SIZE / 2);
	
	info->player.radius = 10;
	info->player.turn_direction = 0;
	info->player.walk_direction = 0;
	info->player.move_updown = 0;
	info->player.move_rightleft = 0;
	info->player.rotation_angle = M_PI_2;
	info->player.move_speed = 3;
	info->player.rotation_speed = 1.7 * (M_PI / 180);
	info->player.plane_dis = (info->width / 2) / tan(deg_to_rad(FOV_ANGLE / 2));
	info->player.ray = ft_malloc(sizeof(t_ray) * NUM_RAYS);
}

void	init_img_data(t_info *info)
{
	t_data	data;
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
}
