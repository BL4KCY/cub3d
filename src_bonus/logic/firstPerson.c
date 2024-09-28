#include "cub3d.h"

void	update_player_status(t_info *info, int indx)
{
	int		start_x;
	int		start_y;

	start_x = (WIDTH / 2) - (info->weapon[info->active_weapon_id].img[indx].width / 2);
	start_y = HEIGHT - info->weapon[info->active_weapon_id].img[indx].height;
	draw_img(&info->map.data, info->weapon[info->active_weapon_id].img[indx], start_x, start_y);
}

void	shooting(int *idx, t_weapon weapon)
{
	if (*idx < weapon.shooting_frame)
		*idx = weapon.shooting_frame;
	if (*idx < weapon.shooting_frame_max)
		(*idx)++;
	else
		*idx = weapon.shooting_frame;
	if (*idx > weapon.n_frames - 1)
		(*idx) = 0;
}

void	aiming(int *idx, t_weapon weapon)
{
	if (*idx < weapon.aiming_frame)
		*idx = weapon.aiming_frame;
	if (*idx < weapon.aiming_frame_max)
		(*idx)++;
	else
		*idx = weapon.aiming_frame;
	if (*idx > weapon.n_frames - 1)
		(*idx) = 0;
}

void	whiping(int *idx, t_weapon weapon)
{
	if (*idx < weapon.whiping_frame)
		*idx = weapon.whiping_frame;
	if (*idx < weapon.whiping_frame_max)
	{
		(*idx)++;
	}
	else
		*idx = weapon.whiping_frame;
	if (*idx > weapon.n_frames - 1)
		(*idx) = 0;
}

void	guarding(int *idx, t_weapon weapon)
{
	*idx = 17;
	if (*idx > weapon.n_frames - 1)
		(*idx) = 0;
}

void	kneeling(int *idx, t_weapon weapon)
{
	if (*idx < weapon.kneeling_frame)
		*idx = weapon.kneeling_frame;
	if (*idx < weapon.kneeling_frame_max)
		(*idx)++;
	else
		*idx = weapon.kneeling_frame;
	if (*idx > weapon.n_frames - 1)
		(*idx) = 0;
}

void	first_person_view(t_info *info)
{
	static int		idx = 0;
	static clock_t	last_time;
	clock_t			current_time;

	current_time = clock();
	double diff_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000;
	if (diff_time > info->weapon[info->active_weapon_id].delay_frame)
	{
		last_time = current_time;
		if (info->weapon[info->active_weapon_id].is_shooting)
			shooting(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_aiming)
			aiming(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_whiping)
			whiping(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_guarding)
			guarding(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_kneeling)
			kneeling(&idx, info->weapon[info->active_weapon_id]);
		else
			idx = 0;
	}
	update_player_status(info, idx);
}