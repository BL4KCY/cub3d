#ifndef ENUMS_H
# define ENUMS_H
typedef enum e_texture_direction
{
	NORTH_ID,
	SOUTH_ID,
	EAST_ID,
	WEST_ID,
	DOOR_ID
}	t_texture_direction;

typedef enum
{
	EMPTY,
	WALL = 1,
	C_DOOR = 4,
	O_DOOR = 8
}	t_type;

typedef enum
{
	PISTOL,
	KNIFE,
	HAND,
	MACHINEGUN
}	t_weapon_type;

#endif
