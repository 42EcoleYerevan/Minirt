#include "minirt.h"

t_vplane	*get_new_vplane(float width, float height, float fov)
{
	t_vplane	*new;
	float		aspect_ratio;

	fov = 1;
	(void)fov;
	new = malloc(sizeof(t_vplane));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	aspect_ratio = width / height;
	new->width = 1;
	new->height = new->width / aspect_ratio;
	new->x_pixel = new->width / width;
	new->y_pixel = new->height / height;
	return (new);
}
