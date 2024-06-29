#include "cub3d.h"



int	ft_exit(t_info *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	free(mlx->mlx);
	exit(0);
}
