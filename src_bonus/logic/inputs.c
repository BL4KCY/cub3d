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
	if (keycode == NUM_1)
		info->active_weapon_id = 0;
	if (keycode == NUM_2)
		info->active_weapon_id = 1;
	if (keycode == NUM_3)
		info->active_weapon_id = 2;
	if (keycode == NUM_4)
		info->active_weapon_id = 3;
	if (keycode == G)
		info->weapon[info->active_weapon_id].is_guarding = true;
	if (keycode == Q)
		info->weapon[info->active_weapon_id].is_kneeling = true;
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
	if (keycode == G)
		info->weapon[info->active_weapon_id].is_guarding = false;
	if (keycode == Q)
		info->weapon[info->active_weapon_id].is_kneeling = false;
	return (0);
}

int	mousepress(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		info->weapon[info->active_weapon_id].is_shooting = true;
	if (button == RIGHT_CLICK)
		info->weapon[info->active_weapon_id].is_aiming = true;
	if (button == SCROLL_UP & info->weapon[info->active_weapon_id].is_whiping == false)
	{
		info->active_weapon_id++;
		if (info->active_weapon_id == N_WEAPONS)
			info->active_weapon_id = 0;
	}
	if (button == SCROLL_DOWN & info->weapon[info->active_weapon_id].is_whiping == false)
	{
		info->active_weapon_id--;
		if (info->active_weapon_id == -1)
			info->active_weapon_id = N_WEAPONS - 1;
	}
	if (button == SCROLL_CLICK)
	{
		info->weapon[info->active_weapon_id].is_whiping = true;
	}
	
	return (0);
}

int	mouserelease(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		info->weapon[info->active_weapon_id].is_shooting = false;
	if (button == RIGHT_CLICK)
		info->weapon[info->active_weapon_id].is_aiming = false;
	if (button == SCROLL_CLICK)
		info->weapon[info->active_weapon_id].is_whiping = false;
	return (0);
}

int	mousemove(int x, int y, t_info *info)
{
	(void)y;
	if (x > WIDTH / 2)
	{
		mlx_mouse_move(info->mlx, info->win, WIDTH / 2, HEIGHT / 2);
		info->player.rotation_angle += MOUSE_X_SENSITIVITY;
	}
	if (x < WIDTH / 2)
	{
		mlx_mouse_move(info->mlx, info->win, WIDTH / 2, HEIGHT / 2);
		info->player.rotation_angle -= MOUSE_X_SENSITIVITY;
	}
	return (0);
}