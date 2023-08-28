#include <minirt.h>

float	cacl_diffuse(t_vec *l, t_vec *n, t_light *light)
{
	float	dot;

	dot = ft_vec_mult_dot(n, l);
	if (dot > 0)
		return ((light->brightness * dot) / (ft_vec_len(n) * ft_vec_len(l)));
	return (0);
}

float	calc_specular(t_vec	*d, t_vec *l, t_light *light, t_figure *figure)
{
	t_vec	*v;
	t_vec	*r;
	float	r_dot_v;
	float	res;

	res = 0;
	v = new_vector(2 * figure->normal->x,
			2 * figure->normal->y, 2 * figure->normal->z);
	ft_vec_mult(v, ft_vec_mult_dot(figure->normal, l));
	r = ft_vec_substr(v, l);
	v = new_vector(-(d->x), -(d->y), -(d->z));
	r_dot_v = ft_vec_mult_dot(r, v);
	if (r_dot_v > 0)
		res = light->brightness
			* powf(r_dot_v / (ft_vec_len(r) * ft_vec_len(v)), figure->specular);
	free(v);
	free(r);
	return (res);
}

float	calc_light(t_vec *p, t_vec *ray, t_scene *scene, t_figure *figure)
{
	float		bright;
	t_vec		*l;
	t_light		*light;
	t_figure	*shadow;

	shadow = NULL;
	light = scene->light;
	bright = scene->ambient->brightness;
	while (light)
	{
		l = ft_vec_substr(light->center, p);
		if (closest_inter(scene->figure, &shadow, p, l) <= 1
			&& shadow != NULL)
		{
			light = light->next;
			free(l);
			continue ;
		}
		bright += cacl_diffuse(l, figure->normal, light);
		if (figure->specular > 0)
			bright += calc_specular(ray, l, light, figure);
		light = light->next;
		free(l);
	}
	return (bright);
}
