#include "cub3d.h"


void	init_map(t_info *mlx)
{
	char	**grid = malloc(sizeof(char*) * 12);
	for (int i = 0; i < 11;i++)
		grid[i] = malloc(sizeof(char) * 16);
	ft_strlcpy(grid[0], "111111111111111", 16);
	ft_strlcpy(grid[1], "100000000000101", 16);
	ft_strlcpy(grid[2], "100001000000101", 16);
	ft_strlcpy(grid[3], "111100000000101", 16);
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
	mlx->map.data.img = NULL;
}

void	init_player(t_info *mlx)
{
	mlx->player.x = mlx->map.n_cols * TILE_SIZE / 2;
	mlx->player.y = mlx->map.n_row * TILE_SIZE / 2;
	mlx->player.radius = 4;
	mlx->player.turn_direction = 0;
	mlx->player.walk_direction = 0;
	mlx->player.rotation_angle = M_PI_2;
	mlx->player.move_speed = 0.5;
	mlx->player.rotation_speed = 0.5 * (M_PI / 180);
}
