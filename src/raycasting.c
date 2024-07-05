#include "cub3d.h"

void	create_rays(t_info *info)
{
	double	ray_angle;

	ray_angle = info->player.rotation_angle - deg_to_rad(FOV_ANGLE / 2);
	for (int i = 0; i < NUM_RAYS ; i++)
	{
		info->player.ray[i].ray_ang = normalize_angle(ray_angle);
		info->player.ray[i].is_ray_down = (info->player.ray[i].ray_ang > 0 && info->player.ray[i].ray_ang < M_PI);
		info->player.ray[i].is_ray_up = !info->player.ray[i].is_ray_down;
		info->player.ray[i].is_ray_right = (info->player.ray[i].ray_ang <= 0.5 * M_PI || info->player.ray[i].ray_ang > 1.5 * M_PI);
		info->player.ray[i].is_ray_left = !info->player.ray[i].is_ray_right;
		ray_angle += deg_to_rad(FOV_ANGLE) / NUM_RAYS;
	}
}
bool	hit_wall(t_info *info, double x, double y)
{
	return (info->map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1');
}

double	distence_ray(t_info *info, double x ,double y)
{
	if (info->player.x == x && info->player.y == y)
		return (__DBL_MAX__);
	return (sqrt(pow(x - info->player.x, 2) + pow(y - info->player.y, 2)));
}

void	raycasting(t_info *info)
{
	t_intersec	intersec;

	intersec.h_dis = 0;
	intersec.v_dis = 0;
	intersec.h.x = 0;
	intersec.h.y = 0;
	intersec.v.x = 0;
	intersec.v.y = 0;
	create_rays(info);
	printf("*********************************************\n");
	for (int i = 0; i < NUM_RAYS;i++)
	{
		set_horizonal_intersection(info, &intersec, i);
		set_vertical_intersection(info, &intersec, i);
		// intersec.h_dis = __DBL_MAX__;
		// intersec.v_dis = __DBL_MAX__;
		if (intersec.h_dis < intersec.v_dis)
			info->player.ray[i].ray_dis = intersec.h_dis;
		else
			info->player.ray[i].ray_dis = intersec.v_dis;
		intersec.h_dis == __DBL_MAX__
		? printf("hor dis[%i]: max   \t%s\t%.2lf",i, info->player.ray[i].is_ray_down ? "down":"up", rad_to_deg(info->player.ray[i].ray_ang))
		: printf("hor dis[%i]: %.2f\t%s\t%.2lf",i, intersec.h_dis, info->player.ray[i].is_ray_down ? "down":"up", rad_to_deg(info->player.ray[i].ray_ang));
		intersec.v_dis == __DBL_MAX__
		? printf(", ver dis[%i]: max   \t%s\t%2.lf\n",i, info->player.ray[i].is_ray_right ? "right":"left", rad_to_deg(info->player.ray[i].ray_ang))
		: printf(", ver dis[%i]: %.2f\t%s\t%2.lf\n",i, intersec.v_dis, info->player.ray[i].is_ray_right ? "right":"left", rad_to_deg(info->player.ray[i].ray_ang));
		// printf("player x: %f, player y: %f, ray angle: %f, ray dis: %f\n", info->player.x, info->player.y, rad_to_deg(info->player.ray[i].ray_ang), info->player.ray[i].ray_dis);
	}
	printf("*********************************************\n");
}
