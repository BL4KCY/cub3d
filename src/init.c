#include "cub3d.h"


void	init_map(t_info *info)
{
	char	**grid = malloc(sizeof(char*) * 12);
	for (int i = 0; i < 11;i++)
		grid[i] = malloc(sizeof(char) * 16);
	ft_strlcpy(grid[0], "111111111111111", 16);
	ft_strlcpy(grid[1], "100000100000101", 16);
	ft_strlcpy(grid[2], "100011000000101", 16);
	ft_strlcpy(grid[3], "101100000000101", 16);
	ft_strlcpy(grid[4], "100000000000101", 16);
	ft_strlcpy(grid[5], "100000001111101", 16);
	ft_strlcpy(grid[6], "100000000000001", 16);
	ft_strlcpy(grid[7], "100010000000001", 16);
	ft_strlcpy(grid[8], "111110000111101", 16);
	ft_strlcpy(grid[9], "100000000000001", 16);
	ft_strlcpy(grid[10], "111111111111111", 16);
	grid[11] = NULL;
	info->map.grid = grid;
	info->map.n_row = 11;
	info->map.n_cols = 15;
	info->width = info->map.n_cols * TILE_SIZE;
	info->height = info->map.n_row * TILE_SIZE;
	info->map.data.img = NULL;
}

void	init_player(t_info *info)
{
	info->player.x = info->width / 2;
	info->player.y = info->height / 2;
	info->player.radius = 4;
	info->player.turn_direction = 0;
	info->player.walk_direction = 0;
	info->player.rotation_angle = M_PI_2;
	info->player.move_speed = 2;
	info->player.rotation_speed = 0.5 * (M_PI / 180);
	info->player.ray = malloc(sizeof(t_ray) * NUM_RAYS);
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
