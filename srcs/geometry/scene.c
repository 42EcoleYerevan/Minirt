#include "minirt.h"

t_scene		*new_scene(t_ambient *abt, t_camera *cam, float wdth, float hgth)
{
	t_scene		*new;

	new = malloc(sizeof(t_scene));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->cams = cam;
	new->width = wdth;
	new->height = hgth;
	new->ambient = abt;
	new->light = NULL;
	new->sphere = NULL;
	new->cylinder = NULL;
	new->plane = NULL;
	return (new);	
}
