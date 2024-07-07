#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "libft.h"

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
# define ADD 50
# define RNG 4
# define MAX_HEIGHT 1080
# define MAX_WIDTH 1950

#define HEIGHT 720
#define WIDTH 1080
#define TILE_SIZE 60
#define MINIMAP_SCALE_FAC 0.1
#define FOV_ANGLE 60
#define STRIP_WIDTH 1
#define NUM_RAYS WIDTH
// #define BCOLOR 0X00BB885E
#define BCOLOR 0x00a0c6c0
// #define BCOLOR 0X00FFFFFF

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coor
{
	double	x;
	double	y;
}			t_coor;

typedef struct	s_intersec
{
	t_coor	h;
	t_coor	v;
	t_coor	step;
	t_coor	intersec;
	double	v_dis;
	double	h_dis;
}			t_intersec;

typedef struct s_ray
{
	double	ray_ang;
	double	ray_dis;
	double	strip_height;
	bool	is_hor;
	bool	is_ray_up;
	bool	is_ray_down;
	bool	is_ray_left;
	bool	is_ray_right;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	radius;
	t_ray	*ray;
	double	turn_direction;
	double	walk_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	double	plane_dis;
}	t_player;

typedef struct s_map
{
	char	**grid;
	t_data	data;
	int		n_row;
	int		n_cols;
}	t_map;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			height;
	int			width;
	t_map		map;
	t_player	player;
}	t_info;

int		ft_exit(t_info *mlx);
void	*get_info(void);
int		keypress(int keycode, t_info *mlx);
int		keyrelease(int keycode, t_info *mlx);
int		rendering(t_info *info);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	*put_rec(void *mlx, int w, int h, int color);
void	rect(t_data *data, int x, int y, int height, int width, int color);
void	init_map(t_info *mlx);
void	init_player(t_info *mlx);
void	draw_cir(t_data *data, int x, int y, int radius, int color);
void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
void	raycasting(t_info *info);
void	render_rays(t_info *mlx, t_ray *ray);
double	normalize_angle(double angle);
void	set_horizonal_intersection(t_info *info, t_intersec *intersec, int id);
bool	hit_wall(t_info *info, double x, double y);
double	distence_ray(t_info *info, double x ,double y);
void	set_vertical_intersection(t_info *info, t_intersec *intersec, int id);

#endif
