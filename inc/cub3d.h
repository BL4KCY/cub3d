#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "structs.h"
# include "enums.h"
# include "pars_cub3d.h"

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 2
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define MAX_HEIGHT 1080
# define MAX_WIDTH 1950

#define HEIGHT 720
#define WIDTH 1080
#define T_SIZE 64
#define MM_RAD 200
#define MINIMAP_SCALE_FAC 0.5
#define STRIP_WIDTH 1
#define NUM_RAYS  WIDTH / STRIP_WIDTH
#define FOV_ANGLE 60
// #define STRIP_WIDTH 1
// #define NUM_RAYS WIDTH
// #define BCOLOR 0X00BB885E
#define BCOLOR 0x00a0c6c0
#define BLUE 0x000000FF
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define YELLOW 0x00FFFF00
#define WHITE 0x00FFFFFF
#define BLACK 0x00000000
#define BROWN 0x00820421
#define DARK_BROWN 0x0041393c
#define PINK 0x00FF69B4
#define GRAY 0x007a7a7a
#define LIGHT_ORANGE 0x00db8858
#define DARK_ORANGE 0x00a8592c
#define DARK_GRAY 0x00404040
#define BLUE_SKY 0x0087CEEB
#define DARK_BLUE 0x00190482
#define CYAN 0x0000FFFF
// #define BCOLOR 0X00FFFFFF
#define CCOLOR 0x0088f6ff
#define FCOLOR 0x00b8aa9f

int		ft_exit(t_info *mlx);
void	*get_info(void);
int		keypress(int keycode, t_info *mlx);
int		keyrelease(int keycode, t_info *mlx);
int		rendering(t_info *info);
void	my_mlx_pixel_set(t_data *data, int x, int y, int color);
void	init_map(t_info *mlx);
void	init_player(t_info *mlx);
void	init_texture(t_info *info);
void	init_img_data(t_info *mlx);
void	rect(t_data *data, t_rect rect);
void	rect_cir(t_data *data, t_rect_cir rect_cir);
void	draw_cir(t_data *data, t_cir cir);
void	draw_line(t_data *data, t_line line);
void	line_in_cir(t_data *data, t_line line, t_cir cir);
void	draw_empty_cir(t_data *data, t_cir circle);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
int		rgb_int(int t, int r, int g, int b);
void	raycasting(t_info *info);
void	update_3d(t_info *info);
void	render_rays(t_info *mlx);
int		update_minimap(t_info *info);
void	update_player_position(t_info *info);
void	update_player(t_info *info);
double	normalize_angle(double angle);
void	set_horizonal_intersection(t_info *info, t_intersec *intersec, int id);
bool	hit_wall(t_info *info, double x, double y);
double	distence_ray(t_info *info, double x ,double y);
void	set_vertical_intersection(t_info *info, t_intersec *intersec, int id);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);

#endif

