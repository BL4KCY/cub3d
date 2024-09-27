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
	if (keycode == R)
		info->weapon.is_reloading = true;
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
	if (keycode == R)
		info->weapon.is_reloading = false;
	return (0);
}

int	mousepress(int button, int x, int y, t_info *info)
{
	if (button == LEFT_CLICK)
		info->weapon.is_shooting = true;
	if (button == RIGHT_CLICK)
		info->weapon.is_aiming = true;
	return (0);
}

int	mouserelease(int button, int x, int y, t_info *info)
{
	if (button == LEFT_CLICK)
		info->weapon.is_shooting = false;
	if (button == RIGHT_CLICK)
		info->weapon.is_aiming = false;
	return (0);
}