#include "cub3d.h"


void	init_map(t_info *mlx)
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
	mlx->map.grid = grid;
	mlx->map.n_row = 11;
	mlx->map.n_cols = 15;
	mlx->width = mlx->map.n_cols * TILE_SIZE;
	mlx->height = mlx->map.n_row * TILE_SIZE;
	mlx->map.data.img = NULL;
}

void	init_player(t_info *mlx)
{
	mlx->player.x = mlx->width / 2;
	mlx->player.y = mlx->height / 2;
	mlx->player.radius = 4;
	mlx->player.turn_direction = 0;
	mlx->player.walk_direction = 0;
	mlx->player.rotation_angle = M_PI_2;
	mlx->player.move_speed = 2;
	mlx->player.rotation_speed = 0.5 * (M_PI / 180);
	mlx->player.ray = malloc(sizeof(t_ray) * NUM_RAYS);
}

void	init_texture(t_info *info)
{
	t_tex *tex;

	tex = &info->tex;
	tex->ea_data.img = mlx_xpm_file_to_image(info->mlx,
			"textures/walls/1.xpm",
			(int *)&info->tex.ea_dem.x,
			(int *)&info->tex.ea_dem.y);
	tex->ea_data.addr = mlx_get_data_addr(tex->ea_data.img, &tex->ea_data.bits_per_pixel,
									&tex->ea_data.line_length, &tex->ea_data.endian);
}
