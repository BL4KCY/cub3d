#include "cub3d.h"


void	start_end_strip(t_info *info, int *wall_top, int *wall_bottom, int id)
{
	*wall_top = (HEIGHT / 2) - (info->player.ray[id].strip_height / 2);
	*wall_top = (*wall_top >= 0) * *wall_top;
	*wall_bottom = *wall_top + info->player.ray[id].strip_height;
	*wall_bottom = (*wall_bottom <= HEIGHT) * *wall_bottom + (*wall_bottom > HEIGHT) * HEIGHT;
}

void	set_wall_tex_pixel(t_info *info, int x, int y)
{
	int	dis_from_top;
	int	direction;
	int	color;

	if (info->player.ray[x].is_hor)
	{
		if (info->player.ray[x].is_ray_up)
			direction = NORTH;
		else
			direction = SOUTH;
	}
	else
	{
		if (info->player.ray[x].is_ray_left)
			direction = WEST;
		else
			direction = EAST;
	}
	dis_from_top = y + (info->player.ray[x].strip_height / 2) - (HEIGHT / 2);
	info->tex.offset_y = dis_from_top
		* (info->tex.img[direction].height / info->player.ray[x].strip_height);
	info->tex.offset_x = ((int)info->player.ray[x].hit_y % T_SIZE) * (info->tex.img[direction].width / T_SIZE);
	if (info->player.ray[x].is_hor)
		info->tex.offset_x = ((int)info->player.ray[x].hit_x % T_SIZE) * (info->tex.img[direction].width / T_SIZE);
	color = my_mlx_pixel_get(&info->tex.img[direction].data,
						info->tex.offset_x, info->tex.offset_y);
	my_mlx_pixel_set(&info->map.data, x, y, color);
}

void	update_3d(t_info *info)
{
	int	x;
	int	y;
	int	wall_top;
	int	wall_bottom;

	x = -1;
	while (++x < NUM_RAYS)
	{
		start_end_strip(info, &wall_top, &wall_bottom, x);
		draw_line(&info->map.data, (t_line){
			x, 0, x, wall_top, info->tex.ceiling_pcolor, 0, 0, 0});
		y  = wall_top - 1;
		while (++y < wall_bottom)
		{
			set_wall_tex_pixel(info, x, y);
		}
		draw_line(&info->map.data, (t_line){
			x, wall_bottom, x, HEIGHT, info->tex.floor_pcolor, 0, 0, 0});
	}
}