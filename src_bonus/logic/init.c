#include "cub3d.h"

void	set_walls(t_info *info, t_queue *door_coor)
{
	while (door_coor)
	{
		info->map.grid[door_coor->x][door_coor->y] = 'B';
		printf("x: %d, y: %d\n", door_coor->x, door_coor->y);
		door_coor = door_coor->next;
	}
}

void	init_map(t_info *info, t_condition *condition)
{
	info->map.grid = condition->pure_map;
	info->map.n_row = condition->height_of_map;
	info->map.n_cols = condition->width_of_map;
	// printf("x_player: %d, y_player: %d\n", condition->x_player, condition->y_player);
	info->map.grid[condition->y_player][condition->x_player] = '0'; 
	info->width = info->map.n_cols * T_SIZE;
	info->height = info->map.n_row * T_SIZE;
	info->map.data.img = NULL;
	set_walls(info, condition->queue);
	mlx_mouse_hide(info->mlx, info->win);
}

// double	get_red

void	init_player(t_info *info, t_condition *condition)
{
	info->player.x = (condition->x_player * T_SIZE) + (T_SIZE / 2);
	info->player.y = (condition->y_player * T_SIZE) + (T_SIZE / 2);
	
	info->player.radius = 8;
	info->player.turn_direction = 0;
	info->player.walk_direction = 0;
	info->player.move_updown = 0;
	info->player.move_rightleft = 0;
	info->player.rotation_angle = condition->r_ang;
	info->player.move_speed = 5;
	info->player.rotation_speed = 3 * (M_PI / 180);
	info->player.plane_dis = (WIDTH / 2) / tan(deg_to_rad(FOV_ANGLE) / 2);
	info->player.ray = ft_malloc(sizeof(t_ray) * NUM_RAYS);
}

void	init_first_person_view(t_info *info)
{
	int	i;

	info->weapon.is_shooting = false;
	info->weapon.is_aiming = false;
	info->weapon.is_reloading = false;
	info->weapon.n_frames = W_FRAMES;
	info->weapon.img = ft_malloc(sizeof(t_img) * (info->weapon.n_frames + 1));
	info->weapon.img[0].path = "textures/firstPerson/attack-pistol/1.xpm";
	info->weapon.img[1].path = "textures/firstPerson/attack-pistol/2.xpm";
	info->weapon.img[2].path = "textures/firstPerson/attack-pistol/3.xpm";
	info->weapon.img[3].path = "textures/firstPerson/attack-pistol/4.xpm";
	info->weapon.img[4].path = "textures/firstPerson/attack-pistol/5.xpm";
	info->weapon.img[5].path = "textures/firstPerson/attack-pistol/6.xpm";
	info->weapon.img[6].path = "textures/firstPerson/attack-pistol/7.xpm";
	info->weapon.img[7].path = "textures/firstPerson/attack-pistol/8.xpm";

	i = -1;
	while (++i < info->weapon.n_frames)
	{
		info->weapon.img[i].data.img = mlx_xpm_file_to_image(info->mlx,
			info->weapon.img[i].path,
			&info->weapon.img[i].width,
			&info->weapon.img[i].height);
		info->weapon.img[i].data.addr = mlx_get_data_addr(info->weapon.img[i].data.img,
			&info->weapon.img[i].data.bits_per_pixel,
			&info->weapon.img[i].data.line_length,
			&info->weapon.img[i].data.endian);
	}
}

void	init_img_data(t_info *info)
{
	t_data	data;
	if (info->map.data.img)
		mlx_destroy_image(info->mlx, info->map.data.img);
	data.img =  mlx_new_image(info->mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
								&data.line_length, &data.endian);
	info->map.data.addr = data.addr;
	info->map.data.img = data.img;
	info->map.data.bits_per_pixel = data.bits_per_pixel;
	info->map.data.line_length = data.line_length;
	info->map.data.endian = data.endian;
}
