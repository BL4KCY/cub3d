#include "cub3d.h"

void	raycasting(t_info *info)
{
	double	ray_angle;

	ray_angle = info->player.rotation_angle - deg_to_rad(FOV_ANGLE / 2);
	for (int i = 0; i < NUM_RAYS ; i++)
	{
		info->player.rays[i] = ray_angle;
		ray_angle += deg_to_rad(FOV_ANGLE) / NUM_RAYS;
	}
}
