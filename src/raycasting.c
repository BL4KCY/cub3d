#include "cub3d.h"

void	create_rays(t_info *info)
{
	double	ray_angle;

	ray_angle = info->player.rotation_angle - deg_to_rad(FOV_ANGLE / 2);
	for (int i = 0; i < NUM_RAYS ; i++)
	{
		info->player.ray[i].ray_ang = normalize_angle(ray_angle);
		info->player.ray[i].is_ray_down = (ray_angle > 0 && ray_angle < M_PI);
		info->player.ray[i].is_ray_up = !info->player.ray[i].is_ray_down;
		info->player.ray[i].is_ray_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
		info->player.ray[i].is_ray_left = !info->player.ray[i].is_ray_right;
		ray_angle += deg_to_rad(FOV_ANGLE) / NUM_RAYS;
	}
}

bool	hit_wall(t_info *info, double x, double y)
{
	// printf("i = %d | j = %d\n",(int)(y / TILE_SIZE), (int)(x / TILE_SIZE));
	return (info->map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1');
}

double	distence_ray(t_info *info, double x ,double y)
{
	return (sqrt(pow(info->player.x - x, 2) + pow(info->player.y - y, 2)));
}

bool	update_intersec(t_info *info, t_intersec *intersec)
{
	double	next_x;
	double	next_y;

	next_x = intersec->h.x + intersec->step.x;
	next_y = intersec->h.y + intersec->step.y;
	if (next_x < 0 || next_x > info->map.n_cols * TILE_SIZE || next_y < 0 || next_y > info->map.n_row * TILE_SIZE)
	{
		if (next_x < 0)
			intersec->h.x = 0;
		if (next_x > info->map.n_cols * TILE_SIZE)
			intersec->h.x = info->map.n_cols * TILE_SIZE;
		if (next_y < 0)
			intersec->h.y = 0;
		if (next_y > info->map.n_row * TILE_SIZE)
			intersec->h.y = info->map.n_row * TILE_SIZE;
		return (false);
	}
	else
	{
		intersec->h.x = next_x;
		intersec->h.y = next_y;
		return (true);
	}
}

void	set_horizonal_intersection(t_info *info, t_intersec *intersec, int id)
{
	intersec->h.y = floor(info->player.y / TILE_SIZE) * TILE_SIZE;
	intersec->h.x = info->player.x + ((intersec->h.y - info->player.y) / tan(info->player.ray[id].ray_ang));
	intersec->step.y = TILE_SIZE;
	intersec->step.x = TILE_SIZE / tan(info->player.ray[id].ray_ang);
	if (info->player.ray[id].is_ray_up)
		intersec->step.y *= -1;
	if (info->player.ray[id].is_ray_left && intersec->step.x > 0)
		intersec->step.x *= -1;
	if (info->player.ray[id].is_ray_right && intersec->step.x < 0)
		intersec->step.x *= -1;
	if (info->player.ray[id].is_ray_up)
		intersec->h.y--;
	while (update_intersec(info, intersec))
	{
		if (hit_wall(info, intersec->h.x, intersec->h.y))
			break ;
	}
	printf("x = %f | y = %f\n", intersec->h.x, intersec->h.y);
	intersec->h_dis = distence_ray(info, intersec->h.x, intersec->h.y);
}

void	raycasting(t_info *info)
{
	t_intersec	intersec;

	create_rays(info);
	for (int i = 0; i < NUM_RAYS;i++)
	{
		set_horizonal_intersection(info, &intersec, i);
		info->player.ray[i].ray_dis = intersec.h_dis;
	}
}
