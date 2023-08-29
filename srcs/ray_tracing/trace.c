#include "minirt.h"

float	closest_inter(t_figure *figure, t_figure **obj, t_vec *o, t_vec *d)
{
	float	min_t;
	float	t;

	min_t = INFINITY;
	while (figure)
	{
		if (figure->type == SPHERE)
			t = sphere_inter(o, d, (t_sphere *)figure->data);
		if (figure->type == PLANE)
			t = plane_inter(o, d, (t_plane *)figure->data);
		if ((t >= 0.001) && (t < min_t))
		{
			min_t = t;
			*obj = figure;
		}
		figure = figure->next;
	}
	return (min_t);
}

int	ray_trace(t_vec *d, t_vec *o, t_scene *scene, t_figure *figure)
{
	float		min_t;
	t_figure	*obj;
	t_vec		*p;
	int			color;

	obj = NULL;
	min_t = closest_inter(figure, &obj, o, d);
	if (obj == NULL)
		return (0);
	p = new_vector(d->x * min_t, d->y * min_t, d->z * min_t);
	ft_vec_add(p, o);
	if (obj && obj->type == PLANE)
		obj->normal = ft_vec_dup(((t_plane *)obj->data)->normal);
	else
	{
		obj->normal = ft_vec_substr(p, ((t_sphere *)obj->data)->center);
		ft_vec_norm(obj->normal);
	}
	color = get_color(obj->color->r, obj->color->g, obj->color->b,
			calc_light(p, d, scene, obj));
	free(obj->normal);
	free(p);
	return (color);
}

void	scene_render(void *mlx, void *win, t_scene *scene, int mlx_x, int mlx_y)
{
	float		x_angle;
	float		y_angle;
	t_vplane	*vplane;
	t_vec		*ray;

	vplane = new_vplane(scene->width, scene->height, scene->cams->fov);
	scene->vplane = vplane;
	y_angle = scene->height / 2;
	while (y_angle >= (scene->height / 2) * (-1))
	{
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			ray = new_vector(x_angle * vplane->x_pixel,
					y_angle * vplane->y_pixel, -1);
			mlx_pixel_put(mlx, win, mlx_x, mlx_y,
				ray_trace(ray, scene->cams->origin, scene, scene->figure));
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}
