#include "minirt.h"

t_vplane	*get_new_vplane(float width, float height, float fov)
{
	t_vplane	*new;
	float		aspect_ratio;

	(void)fov;
	new = malloc(sizeof(t_vplane));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	aspect_ratio = width / height;
	new->width = tan(fov / 2 * (M_PI / 180)) * 2;
	new->height = new->width / aspect_ratio;
	new->x_pixel = new->width / width;
	new->y_pixel = new->height / height;
	return (new);
}
