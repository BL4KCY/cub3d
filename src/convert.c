#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / M_PI));
}

int	rgb_int(int t, int r, int g, int b)
{
	r = (r > 255) * r + (r < 0) * 0 + (r >= 0 && r <= 255) * r;
	g = (g > 255) * g + (g < 0) * 0 + (g >= 0 && g <= 255) * g;
	b = (b > 255) * b + (b < 0) * 0 + (b >= 0 && b <= 255) * b;
	t = (t > 255) * t + (t < 0) * 0 + (t >= 0 && t <= 255) * t;
	if (t)
	{
		r = (r * t) / 255;
		g = (g * t) / 255;
		b = (b * t) / 255;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

