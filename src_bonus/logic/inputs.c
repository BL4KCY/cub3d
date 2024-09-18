#include "cub3d.h"

int	keypress(int keycode, t_info *mlx)
{
	if (keycode == ESC)
		ft_exit(mlx);
	if (keycode == W)
		mlx->player.walk_direction = 1;
	if (keycode == S)
		mlx->player.walk_direction = -1;
	if (keycode == LEFT)
		mlx->player.turn_direction = -1;
	if (keycode == RIGHT)
		mlx->player.turn_direction = 1;
	if (keycode == A)
		mlx->player.move_rightleft = -1;
	if (keycode == D)
		mlx->player.move_rightleft = 1;
	return (0);
}

int	keyrelease(int keycode, t_info *mlx)
{
	if (keycode == W || keycode == S)
		mlx->player.walk_direction = 0;
	if (keycode == LEFT || keycode == RIGHT)
		mlx->player.turn_direction = 0;
	if (keycode == A || keycode == D)
		mlx->player.move_rightleft = 0;
	return (0);
}
