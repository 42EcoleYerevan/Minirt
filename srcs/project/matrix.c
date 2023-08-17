#include "minirt.h"

t_mat	*get_project_matrix()
{
	t_mat	*matrix;

	matrix = (t_mat *)malloc(sizeof(t_mat));
	if (!matrix)
		return (NULL);
	matrix->x = new_vector(0, 0, 0);
	return (matrix);
}
