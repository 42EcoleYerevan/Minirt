#include "minirt.h"

t_figure	*new_figure(void *data, int type)
{
	t_figure	*new;

	new = malloc(sizeof(t_figure));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->data = data;
	new->type = type;
	new->next = NULL;
	return (new);
}