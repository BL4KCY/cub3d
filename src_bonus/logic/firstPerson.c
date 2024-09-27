#include "cub3d.h"

void	update_player_status(t_info *info, int indx)
{
	int		start_x;
	int		start_y;

	start_x = (WIDTH / 2) - (info->weapon.img[indx].width / 2);
	start_y = HEIGHT - info->weapon.img[indx].height;
	if (indx == 8)
		printf("idx: %d\n", indx);
	draw_img(&info->map.data, info->weapon.img[indx], start_x, start_y);
}

void	shooting(int *idx)
{
	if (*idx < 6)
		*idx = 6;
	else
		*idx = 3;
}

void	aiming(int *idx)
{
	if (*idx < 2)
		(*idx)++;
	else
		*idx = 2;
}

void	first_person_view(t_info *info)
{
	static int		idx = 0;
	static clock_t	last_time;
	clock_t			current_time;

	current_time = clock();
	double diff_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000;
	if (diff_time > 40)
	{
		last_time = current_time;
		if (info->weapon.is_shooting)
			shooting(&idx);
		else if (info->weapon.is_aiming)
			aiming(&idx);
		else
			idx = 0;
	}
	update_player_status(info, idx);
}