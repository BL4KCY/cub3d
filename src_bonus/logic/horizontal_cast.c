#include "cub3d.h"

bool	update_intersec_hor(t_info *info, t_intersec *intersec, int id)
{
	static double	start = 0;
	double			next_x;
	double			next_y;

	next_x = intersec->h.x + (intersec->step.x * start);
	next_y = intersec->h.y + (intersec->step.y * start);
	if (next_x <= 0 || next_x >= info->width
		|| next_y <= 0 || next_y >= info->height)
	{
		intersec->h.y = info->player.y;
		intersec->h.x = info->player.x;
		return (start = 0, false);
	}
	intersec->h.x = next_x;
	intersec->h.y = next_y;
	if (hit_wall(info, intersec->h.x, intersec->h.y
			- info->player.ray[id].is_ray_up))
		return (start = 0, false);
	start = 1;
	return (true);
}

void	set_horizonal_intersection(t_info *info, t_intersec *intersec, int id)
{
	intersec->h.y = floor(info->player.y / T_SIZE) * T_SIZE;
	if (info->player.ray[id].is_ray_down)
		intersec->h.y += T_SIZE;
	intersec->h.x = info->player.x + ((intersec->h.y - info->player.y)
			/ tan(info->player.ray[id].ray_ang));
	intersec->step.y = T_SIZE;
	if (info->player.ray[id].is_ray_up)
		intersec->step.y *= -1;
	intersec->step.x = T_SIZE / tan(info->player.ray[id].ray_ang);
	if (info->player.ray[id].is_ray_left && intersec->step.x > 0)
		intersec->step.x *= -1;
	if (info->player.ray[id].is_ray_right && intersec->step.x < 0)
		intersec->step.x *= -1;
	while (update_intersec_hor(info, intersec, id))
		;
	intersec->h_dis = distence_ray(info, intersec->h.x, intersec->h.y);
}
