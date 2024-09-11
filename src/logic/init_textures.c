#include "cub3d.h"


void	init_texture(t_info *info)
{
	int		i;
	char	north_path[] = "textures/walls/grayWall.xpm";
	char	south_path[] = "textures/walls/greenWall.xpm";
	char	west_path[] = "textures/walls/redWall.xpm";
	char	east_path[] = "textures/walls/orangeWall.xpm";

	info->tex.img[NORTH].path = north_path;
	info->tex.img[SOUTH].path = south_path;
	info->tex.img[WEST].path = west_path;
	info->tex.img[EAST].path = east_path;
	i = -1;
	while (++i < 4)
	{
		info->tex.img[i].data.img = mlx_xpm_file_to_image(info->mlx,
			info->tex.img[i].path, &info->tex.img[i].width, &info->tex.img[i].height);
		info->tex.img[i].data.addr = mlx_get_data_addr(info->tex.img[i].data.img,
			&info->tex.img[i].data.bits_per_pixel,
			&info->tex.img[i].data.line_length,
			&info->tex.img[i].data.endian);
	}
	info->tex.floor_pcolor = DARK_GRAY;
	info->tex.ceiling_pcolor = BLUE_SKY;
}
