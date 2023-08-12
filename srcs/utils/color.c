#include "minirt.h"

int	get_color(int red, int green, int blue, float bright)
{
	return ((int)(red * bright) << 16 | (int)(green * bright) << 8 | (int)(blue * bright));
}

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}