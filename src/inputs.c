#include "cub3d.h"

int	keyboard(int keycode, t_info *mlx)
{
	if (keycode == ESC)
		ft_exit(mlx);
	return (0);
}
