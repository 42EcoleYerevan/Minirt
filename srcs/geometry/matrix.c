#include "minirt.h"


t_mat	*new_mat(t_vec *x, t_vec *y, t_vec *z, t_vec *w)
{
	t_mat	*res;

	res = (t_mat *)malloc(sizeof(t_mat));
	if (!res)
		err_exit("Malloc error");
	res->x = x;
	res->y = y;
	res->z = z;
	res->w = w;
	return (res);
}

t_mat	*new_zero_mat(void)
{
	t_mat	*res;

	res = (t_mat *)malloc(sizeof(t_mat));
	if (!res)
		err_exit("Malloc error");
	res->x = new_zero_vec();
	res->y = new_zero_vec();
	res->z = new_zero_vec();
	res->w = new_zero_vec();
	return (res);
}

t_mat	*ft_translate_matrix(t_vec *vec)
{
	t_mat	*res;

	res = new_zero_mat();
	res->w = vec;
	return (res);
}
