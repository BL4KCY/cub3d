/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:17:20 by melfersi          #+#    #+#             */
/*   Updated: 2024/06/29 20:33:38 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define KEYPRESSMASK 1
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

#define HEIGHT 800
#define WIDTH 1280
#define TILE_SIZE 32
// #define BCOLOR 0X00BB885E
#define BCOLOR 0X00FFFFFF

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	**grid;
	int		n_row;
	int		n_cols;
}	t_map;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_info;

int		ft_exit(t_info *mlx);
int		keyboard(int keycode, t_info *mlx);
int		rendering(t_info *info);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	*put_rec(void *mlx, int w, int h, int color);

#endif
