#include "cub3d.h"

int	ft_exit(t_info *info)
{
	int		weapon_id;
	int		i;

	i = -1;
	weapon_id = -1;
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_image(info->mlx, info->map.data.img);
	while (++i < 4)
		mlx_destroy_image(info->mlx, info->tex.img[i].data.img);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	ft_hunt_leak();
	exit(0);
}
