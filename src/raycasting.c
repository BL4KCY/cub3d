#include "cub3d.h"

void	create_rays(t_info *info)
{
	double	ray_angle;
	int		i;

	ray_angle = info->player.rotation_angle - deg_to_rad(FOV_ANGLE / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		info->player.ray[i].ray_ang = normalize_angle(ray_angle);
		info->player.ray[i].is_ray_down = (info->player.ray[i].ray_ang > 0
				&& info->player.ray[i].ray_ang < M_PI);
		info->player.ray[i].is_ray_up = !info->player.ray[i].is_ray_down;
		info->player.ray[i].is_ray_right = (info->player.ray[i].ray_ang <= 0.5
				* M_PI || info->player.ray[i].ray_ang > 1.5 * M_PI);
		info->player.ray[i].is_ray_left = !info->player.ray[i].is_ray_right;
		ray_angle += deg_to_rad(FOV_ANGLE) / NUM_RAYS;
	}
}

bool	hit_wall(t_info *info, double x, double y)
{
	return (info->map.grid[(int)(y / T_SIZE)][(int)(x / T_SIZE)] == '1');
}

double	distence_ray(t_info *info, double x, double y)
{
	if (info->player.x == x && info->player.y == y)
		return (__DBL_MAX__);
	return (sqrt(pow(x - info->player.x, 2) + pow(y - info->player.y, 2)));
}

void	raycasting(t_info *info)
{
	int				i;
	t_intersec		intersec;
	double			correct_ray_dis;

	create_rays(info);
	i = -1;
	while (++i < NUM_RAYS)
	{
		set_horizonal_intersection(info, &intersec, i);
		set_vertical_intersection(info, &intersec, i);
		if (intersec.h_dis < intersec.v_dis)
		{
			info->player.ray[i].ray_dis = intersec.h_dis;
			info->player.ray[i].is_hor = true;
			info->player.ray[i].hit_x = intersec.h.x;
			info->player.ray[i].hit_y = intersec.h.y;
		}
		else
		{
			info->player.ray[i].ray_dis = intersec.v_dis;
			info->player.ray[i].is_hor = false;
			info->player.ray[i].hit_x = intersec.v.x;
			info->player.ray[i].hit_y = intersec.v.y;
		}
		correct_ray_dis = info->player.ray[i].ray_dis * cos(info->player.ray[i].ray_ang - info->player.rotation_angle);
		info->player.ray[i].strip_height = (T_SIZE / correct_ray_dis) * info->player.plane_dis;
	}
}
