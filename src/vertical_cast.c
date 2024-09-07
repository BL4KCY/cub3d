#include "cub3d.h"

bool	update_intersec_ver(t_info *info, t_intersec *intersec, int id)
{
	static double	start = 0;
	double			next_x;
	double			next_y;

	next_x = intersec->v.x + (intersec->step.x * start);
	next_y = intersec->v.y + (intersec->step.y * start);
	if (next_x < 0 || next_x > info->width
		|| next_y < 0 || next_y > info->height)
	{
		intersec->v.y = info->player.y;
		intersec->v.x = info->player.x;
		return (start = 0, false);
	}
	intersec->v.x = next_x;
	intersec->v.y = next_y;
	if (hit_wall(info, intersec->v.x
			-info->player.ray[id].is_ray_left, intersec->v.y))
		return (start = 0, false);
	start = 1;
	return (true);
}

void	set_vertical_intersection(t_info *info, t_intersec *intersec, int id)
{
	intersec->v.x = floor(info->player.x / TILE_SIZE) * TILE_SIZE;
	if (info->player.ray[id].is_ray_right)
		intersec->v.x += TILE_SIZE;
	intersec->v.y = info->player.y + ((intersec->v.x - info->player.x)
			* tan(info->player.ray[id].ray_ang));
	intersec->step.x = TILE_SIZE;
	if (info->player.ray[id].is_ray_left)
		intersec->step.x *= -1;
	intersec->step.y = TILE_SIZE * tan(info->player.ray[id].ray_ang);
	if (info->player.ray[id].is_ray_up && intersec->step.y > 0)
		intersec->step.y *= -1;
	if (info->player.ray[id].is_ray_down && intersec->step.y < 0)
		intersec->step.y *= -1;
	while (update_intersec_ver(info, intersec, id))
		;
	intersec->v_dis = distence_ray(info, intersec->v.x, intersec->v.y);
}
