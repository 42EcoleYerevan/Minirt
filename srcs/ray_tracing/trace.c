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
		else if (figure->type == PLANE)
			t = plane_inter(o, d, ((t_plane *)figure->data)->point,
				((t_plane *)figure->data)->normal);
		else
			t = cylinder_inter(o, d, (t_cylinder *)figure->data);
		if ((t >= 0.001) && (t < min_t))
		{
			min_t = t;
			*obj = figure;
			printf("min_t = %f , type %d\n", min_t, (*obj)->type);
		}
		figure = figure->next;
	}
	if (*obj)	
		printf("------------------\n THIS min_t = %f , type %d\n------------------------\n", min_t, (*obj)->type);
	return (min_t);
}

t_vec	*create_sphere_norm(t_vec *p, t_vec *center)
{
	t_vec	*new;

	new = ft_vec_substr(p, center);
	ft_vec_norm(new);
	return (new);
}

t_vec	*new_vec_obj_cross(t_scene *scene, t_figure **obj)
{
	float		min_t;
	t_vec		*p;

	min_t = closest_inter(scene->figure, obj, scene->vecs[1], scene->vecs[0]);
	if (*obj == NULL)
		return (NULL);
	p = new_vector(scene->vecs[0]->x * min_t, scene->vecs[0]->y * min_t,
			scene->vecs[0]->z * min_t);
	ft_vec_add(p, scene->vecs[1]);
	return (p);
}

int	ray_trace(t_scene *scene)
{
	t_figure	*obj;
	t_vec		*p;
	int			color;

	obj = NULL;
	p = new_vec_obj_cross(scene, &obj);
	if (obj == NULL)
		return (0);
	if (obj && obj->type == PLANE)
		obj->normal = ft_vec_dup(((t_plane *)obj->data)->normal);
	else if (obj && obj->type == SPHERE)
		obj->normal = create_sphere_norm(p, ((t_sphere *)obj->data)->center);
	else
		obj->normal = ft_vec_dup(((t_cylinder *)obj->data)->direction);
	color = get_color(obj->color->r, obj->color->g, obj->color->b,
			calc_light(p, scene, obj));
	free(obj->normal);
	free(p);
	return (color);
}

void	scene_render(t_scene *scene, int mlx_x, int mlx_y)
{
	float		x_angle;
	float		y_angle;

	y_angle = scene->height / 2 + 1;
	while (--y_angle >= (scene->height / 2) * (-1))
	{
		x_angle = (scene->width / 2) * (-1) - 1;
		mlx_x = 0;
		while (++x_angle <= scene->width / 2)
		{
			scene->vecs[0] = new_vector(x_angle * scene->vplane->x_pixel,
					y_angle * scene->vplane->y_pixel, -1);
			scene->vecs[1] = scene->cams->origin;
			mlx_pixel_put(scene->mlx, scene->win, mlx_x, mlx_y,
				ray_trace(scene));
			free(scene->vecs[0]);
			mlx_x++;
		}
		mlx_y++;
	}
}
