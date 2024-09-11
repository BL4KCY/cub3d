#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / M_PI));
}

int	rgb_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

