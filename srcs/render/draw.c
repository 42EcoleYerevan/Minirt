#include "minirt.h"

void ft_put_pixel(t_scene *scene, int x, int y, int color)
{
	char *dst;

	dst = scene->addr + (y * scene->line_length + \
					x * (scene->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
