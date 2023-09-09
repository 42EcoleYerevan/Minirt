#include "../../includes/minirt.h"

float	cacl_diffuse(t_vec l, t_vec n, t_light *light)
{
	float	dot;

	dot = ft_vec_mult_dot(n, l);
//	printf("dot diffuse = %f nx %f ny %f nz %f\n", dot, n.x, n.y, n.z);
	if (dot > 0)
	{
		return ((light->brightness * dot) / (ft_vec_len(n) * ft_vec_len(l)));
	}
	return (0);
}

float	calc_specular(t_scene *scene, t_light *light, t_figure *figure)
{
	t_vec	v;
	t_vec	r;
	float	r_dot_v;

	v = new_vector(2 * figure->normal.x,
			2 * figure->normal.y, 2 * figure->normal.z);
	v = ft_vec_mult(v, ft_vec_mult_dot(figure->normal, scene->vecs[2]));
	r = ft_vec_substr(v, scene->vecs[2]);
	v = new_vector(-(scene->vecs[0].x),
			-(scene->vecs[0].y), -(scene->vecs[0].z));
	r_dot_v = ft_vec_mult_dot(r, v);
	if (r_dot_v > 0)
		r_dot_v = light->brightness
			* powf(r_dot_v / (ft_vec_len(r) * ft_vec_len(v)), figure->specular);
	if (r_dot_v < 0)
		return (0);
	return (r_dot_v);
}

int	check_shadow(t_scene *scene, t_light **light, t_vec p)
{
	t_figure	*shadow;

	shadow = NULL;
	if (closest_inter(scene->figure, &shadow, p, scene->vecs[2]) <= 1
		&& shadow != NULL)
	{
		*light = (*light)->next;
		return (1);
	}
	return (0);
}

float	calc_light(t_vec p, t_scene *scene, t_figure *figure)
{
	float		bright;
	t_light		*light;

	light = scene->light;
	bright = scene->ambient->brightness;
	while (light)
	{
		scene->vecs[2] = ft_vec_substr(light->center, p);
		if (check_shadow(scene, &light, p))
			continue ;
		bright += cacl_diffuse(scene->vecs[2], figure->normal, light);
		if (figure->specular > 0)
			bright += calc_specular(scene, light, figure);
		light = light->next;
	}
	return (bright);
}
