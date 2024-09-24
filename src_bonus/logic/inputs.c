#include "cub3d.h"

int	keypress(int keycode, t_info *info)
{
	if (keycode == ESC)
		ft_exit(info);
	if (keycode == W)
		info->player.walk_direction = 1;
	if (keycode == S)
		info->player.walk_direction = -1;
	if (keycode == LEFT)
		info->player.turn_direction = -1;
	if (keycode == RIGHT)
		info->player.turn_direction = 1;
	if (keycode == A)
		info->player.move_rightleft = -1;
	if (keycode == D)
		info->player.move_rightleft = 1;
	if (keycode == E)
		door_key(info);
	return (0);
}

int	keyrelease(int keycode, t_info *info)
{
	if (keycode == W || keycode == S)
		info->player.walk_direction = 0;
	if (keycode == LEFT || keycode == RIGHT)
		info->player.turn_direction = 0;
	if (keycode == A || keycode == D)
		info->player.move_rightleft = 0;
	return (0);
}
