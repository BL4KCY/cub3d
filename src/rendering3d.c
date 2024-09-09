#include "cub3d.h"



void	update_3d(t_info *info)
{
	int	i;
	int	y;
	int	color;

	i = -1;
	// ceiling
	rect(&info->map.data, (t_rect){0, 0, HEIGHT / 2, WIDTH, GRAY});
	// floor
	rect(&info->map.data, (t_rect){0, HEIGHT / 2, HEIGHT / 2, WIDTH, DARK_GRAY});
	while (++i < NUM_RAYS)
	{
		color = (info->player.ray[i].is_hor) * DARK_ORANGE
			+ (!info->player.ray[i].is_hor) * LIGHT_ORANGE;
		y = (HEIGHT / 2) - (info->player.ray[i].strip_height / 2);
		if (y < 0)
			y = 0;
		rect(&info->map.data, (t_rect){
			i * STRIP_WIDTH, y,
			info->player.ray[i].strip_height, STRIP_WIDTH,
			color});
	}
}
