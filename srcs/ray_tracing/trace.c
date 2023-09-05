#include "minirt.h"

float	closest_inter(t_figure *figure, t_figure **obj, t_vec o, t_vec d)
{
	float	min_t;
	float	t;

	t = INFINITY;
	min_t = INFINITY;
	while (figure)
	{
		if (figure->type == SPHERE)
			t = sphere_inter(o, d, (t_sphere *)figure->data);
		else 
		// if (figure->type == PLANE)
			t = plane_inter(o, d, (((t_plane *)figure->data)->point),
				(((t_plane *)figure->data)->normal));
		// else if (figure->type == CYLINDER)
		// 	t = cylinder_inter(o, d, figure);
		if ((t >= 0.0001) && (t < min_t))
		{
			min_t = t;
			*obj = figure;
		}
		figure = figure->next;
	}
	return (min_t);
}

t_vec	create_sphere_norm(t_vec p, t_vec center)
{
	t_vec	new;

	new = ft_vec_norm(ft_vec_substr(p, center));
	return (new);
}

t_vec	new_vec_obj_cross(t_scene *scene, t_figure **obj)
{
	float		min_t;
	t_vec		p;

	min_t = closest_inter(scene->figure, obj, scene->vecs[1], scene->vecs[0]);
	if (*obj == NULL)
		return ((t_vec){0,0,0,0});
	p = ft_vec_add(ft_vec_mult(scene->vecs[0], min_t), scene->vecs[1]);
	return (p);
}

int	ray_trace(t_scene *scene)
{
	t_figure	*obj;
	t_vec		p;
	int			color;

	obj = NULL;
	p = new_vec_obj_cross(scene, &obj);
	if (obj == NULL)
		return (0);
	if (obj && obj->type == PLANE)
		obj->normal = ((t_plane *)obj->data)->normal;
	else if (obj && obj->type == SPHERE)
		obj->normal = create_sphere_norm(p, ((t_sphere *)obj->data)->center);
	else
		obj->normal = ft_vec_dup(((t_cylinder *)obj->data)->direction);
	color = get_color(obj->color->r, obj->color->g, obj->color->b, calc_light(p, scene, obj));
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
			scene->vecs[0] = (t_vec){x_angle * scene->vplane->x_pixel, y_angle * scene->vplane->y_pixel, -1, 1};
			scene->vecs[1] = scene->cams->origin;
			mlx_pixel_put(scene->mlx, scene->win, mlx_x, mlx_y,
				ray_trace(scene));
			mlx_x++;
		}
		mlx_y++;
	}
}
