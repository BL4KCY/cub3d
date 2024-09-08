#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

void	update_player_pos_in_full_map(t_info *info)
{
	int	color;

	color = 0x00FF00;
	draw_cir(&info->map.data, (t_cir){
		MINIMAP_SCALE_FAC * info->player.x,
		MINIMAP_SCALE_FAC * info->player.y, info->player.radius, RED});
	draw_line(&info->map.data, (t_line){
		MINIMAP_SCALE_FAC * info->player.x,
		MINIMAP_SCALE_FAC * info->player.y,
		MINIMAP_SCALE_FAC * info->player.x + MINIMAP_SCALE_FAC * 50
		* cos(info->player.rotation_angle),
		MINIMAP_SCALE_FAC * info->player.y + MINIMAP_SCALE_FAC * 50
		* sin(info->player.rotation_angle), RED});
}

void	full_map(t_info *info)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < info->map.n_row)
	{
		j = -1;
		while (++j < info->map.n_cols)
		{
			color = (info->map.grid[i][j] == '1') * BROWN
				+ (info->map.grid[i][j] == '0') * GRAY;
			rect(&info->map.data, (t_rect){
				j * T_SIZE, i * T_SIZE, T_SIZE, T_SIZE, color});
		}
	}
	update_player_pos_in_full_map(info);
}

int	rendering(t_info *info)
{
	init_img_data(info);
	update_player_position(info);
	raycasting(info);
	// update_3d(info);
	full_map(info);
	render_rays(info);
	update_minimap(info);
	update_player(info);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}
