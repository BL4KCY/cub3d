#ifndef MACROS_H
# define MACROS_H

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 2
// keycodes
# define ESC 65307
# define M 109
# define W 119
# define S 115
# define A 97
# define D 100
# define E 101
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

// resolution
#define HEIGHT 500
#define WIDTH 800
// textures
#define T_SIZE 64
#define MM_RAD 100
#define MINIMAP_SCALE_FAC 0.5
#define MOUSE_SENSITIVITY 0.04
#define STRIP_WIDTH 1
#define NUM_RAYS WIDTH / STRIP_WIDTH
#define MID_ANG_ID NUM_RAYS / 2
#define FOV_ANGLE 60
#define COLLISION_OFFSET 10
#define DOOR_RANGE_DIST 120

// colors
#define RED 0x00FF0000
#define WHITE 0x00FFFFFF
#define BROWN 0x00820421
#define DARK_BROWN 0x0041393c
#define CYAN 0x0000FFFF
#define GREEN 0x0000FF00

// player directions
# define NORTH_P (M_PI * 3 / 2)
# define EAST_P (M_PI * 2)
# define SOUTH_P (M_PI / 2)
# define WEST_P (M_PI)

#endif