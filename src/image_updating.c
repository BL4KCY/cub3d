#include "cub3d.h"

int	update_minimap(t_info *info)
{
	int	color;
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = (info->player.x > MM_RAD) * (info->player.x - MM_RAD);
	y = (info->player.y > MM_RAD) * (info->player.y - MM_RAD);
	while (++i < info->map.n_row)
	{
		j = 0;
		while (j < info->map.n_cols)
		{
			color = (info->map.grid[i][j] == '1') * BROWN
				+ (info->map.grid[i][j] == '0') * WHITE;
			rect_cir(&info->map.data, (t_rect_cir){
				MINIMAP_SCALE_FAC * (j++) * T_SIZE - MINIMAP_SCALE_FAC * x,
				MINIMAP_SCALE_FAC * i * T_SIZE - MINIMAP_SCALE_FAC * y,
				MINIMAP_SCALE_FAC * T_SIZE, MINIMAP_SCALE_FAC * T_SIZE,
				MINIMAP_SCALE_FAC * MM_RAD, MINIMAP_SCALE_FAC * MM_RAD,
				MINIMAP_SCALE_FAC * MM_RAD, color});
		}
	}
	return (0);
}

void	update_player_position(t_info *info)
{
	double	new_x;
	double	new_y;

	info->player.rotation_angle += info->player.rotation_speed
		* info->player.turn_direction;
	info->player.rotation_angle = normalize_angle(info->player.rotation_angle);
	new_x = info->player.x + (cos(info->player.rotation_angle)
			* info->player.move_speed * info->player.walk_direction)
		+ (info->player.move_rightleft * info->player.move_speed);
	new_y = info->player.y + (sin(info->player.rotation_angle)
			* info->player.move_speed * info->player.walk_direction)
		+ (info->player.move_updown * info->player.move_speed);
	if (info->map.grid[(int)(new_y / T_SIZE)][(int)(new_x / T_SIZE)] == '0')
	{
		info->player.x = new_x;
		info->player.y = new_y;
	}
}

void	render_rays(t_info *info)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(&info->map.data, (t_line){
			MINIMAP_SCALE_FAC * info->player.x, MINIMAP_SCALE_FAC * info->player.y,
			MINIMAP_SCALE_FAC * info->player.ray[i].hit_x,
			MINIMAP_SCALE_FAC * info->player.ray[i].hit_y,
			CYAN});
		i++;
	}
}

void	update_player(t_info *info)
{
	int	x2;
	int	y2;
	int	player_x;
	int	player_y;

	player_x = (info->player.x < MM_RAD) * info->player.x
		+ (info->player.x >= MM_RAD) * MM_RAD;
	player_y = (info->player.y < MM_RAD) * info->player.y
		+ (info->player.y >= MM_RAD) * MM_RAD;
	draw_cir(&info->map.data, (t_cir){
		MINIMAP_SCALE_FAC * player_x, MINIMAP_SCALE_FAC * player_y,
		MINIMAP_SCALE_FAC * info->player.radius, BLUE});
	x2 = cos(info->player.rotation_angle) * 40 + player_x;
	y2 = sin(info->player.rotation_angle) * 40 + player_y;
	draw_line(&info->map.data, (t_line){
		player_x * MINIMAP_SCALE_FAC, player_y * MINIMAP_SCALE_FAC,
		x2 * MINIMAP_SCALE_FAC, y2 * MINIMAP_SCALE_FAC,
		BLUE});
}
