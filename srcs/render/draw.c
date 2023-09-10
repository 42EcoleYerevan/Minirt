#include "minirt.h"

void ft_put_pixel(t_scene *scene, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= scene->width || y < 0 || y >= scene->height)
		return ;
	dst = scene->addr + (y * scene->line_length + \
					x * (scene->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
