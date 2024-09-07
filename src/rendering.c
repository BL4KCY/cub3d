#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

int	rendering(t_info *info)
{
	init_img_data(info);
	update_player_position(info);
	raycasting(info);
	// update_3d(info);
	update_minimap(info);
	update_player(info);
	// render_rays(info);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}
