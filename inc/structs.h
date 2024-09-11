#ifndef STRCT_H
# define STRCT_H
# include <stdint.h>
// Image
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// Shape
typedef struct s_rect
{
	float	x;
	float	y;
	float	height;
	float	width;
	float	color;
}	t_rect;

typedef struct s_cir
{
	float	x;
	float	y;
	float	radius;
	float	color;
}	t_cir;

typedef struct s_line
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		color;
	float	x_inc;
	float	y_inc;
	int		step;
}			t_line;

typedef struct rect_cir
{
	float	x;
	float	y;
	float	height;
	float	width;
	float	cir_x;
	float	cir_y;
	float	radius;
	int		color;
}	t_rect_cir;


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
	double	hit_x;
	double	hit_y;
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
	double	move_updown;
	double	move_rightleft;
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


typedef struct s_img
{
	t_data	data;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_tex
{
	t_img	img[4];
	int		offset_x;
	int		offset_y;
	int		floor_pcolor;
	int		ceiling_pcolor;
}	t_tex;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	t_map		map;
	t_player	player;
	t_coor		mouse;
	t_tex		tex;
}	t_info;

// parsing

typedef struct s_condition
{
	char			*name;
	char			**substr;
	int				catch;
	char			**map;
	char			**textures;
	char			**c_flor;
	char			**pure_texture;
	char			**pure_map;
	int				width_of_map;
	int				height_of_map;
	int				x_player;
	int				y_player;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
}					t_condition;

typedef struct s_queue
{
	int				x;
	int				y;
	struct s_queue	*next;
}					t_queue;


#endif
