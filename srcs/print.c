#include "minirt.h"

void	ft_print_light(t_scene *scene);
void	ft_print_camera(t_scene *scene);
void	ft_print_ambient(t_ambient *ambient);

void	ft_print_scene(t_scene *scene)
{
	t_figure *figure;

	ft_print_ambient(scene->ambient);
	ft_print_camera(scene);
	ft_print_light(scene);
	figure = scene->figure;
	while (figure)
	{
		if (figure->type == SPHERE)
			ft_print_sphere(figure->data);
		else if (figure->type == PLANE)
			ft_print_plane(figure->data);
		else if (figure->type == CYLINDER)
			ft_print_cylinder(figure->data);
		figure = figure->next;
	}
}

void	ft_print_ambient(t_ambient *ambient)
{
	printf("Ambient:\n");
	printf("Brightness: %f\n", ambient->brightness);
	printf("Color: %d %d %d\n\n", ambient->color->r, ambient->color->g, ambient->color->b);
}

void	ft_print_camera(t_scene *scene)
{
	t_camera *camera;

	camera = scene->cams;
	printf("Camera:\n");
	printf("Origin: %f %f %f\n", camera->origin->x, camera->origin->y, camera->origin->z);
	printf("Direction: %f %f %f\n", camera->direction->x, camera->direction->y, camera->direction->z);
	printf("FOV: %f\n\n", camera->fov);
}

void	ft_print_light(t_scene *scene)
{
	t_light *light;

	light = scene->light;
	while (light)
	{
		printf("Light:\n");
		printf("Center: %f %f %f\n", light->center->x, light->center->y, light->center->z);
		printf("Brightness: %f\n", light->brightness);
		printf("Color: %d %d %d\n\n", light->color->r, light->color->g, light->color->b);
		light = light->next;
	}
}

void ft_print_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	printf("Center: %f %f %f\n", sphere->center->x, sphere->center->y, sphere->center->z);
	printf("Radius: %f\n", sphere->radius);
	printf("Color: %d %d %d\n\n", sphere->color->r, sphere->color->g, sphere->color->b);
}

void ft_print_plane(t_plane *plane)
{
	printf("Plane:\n");
	printf("Point: %f %f %f\n", plane->point->x, plane->point->y, plane->point->z);
	printf("Normal: %f %f %f\n", plane->normal->x, plane->normal->y, plane->normal->z);
	printf("Color: %d %d %d\n\n", plane->color->r, plane->color->g, plane->color->b);
}

void ft_print_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	printf("Center: %f %f %f\n", cylinder->center->x, cylinder->center->y, cylinder->center->z);
	printf("Direction: %f %f %f\n", cylinder->direction->x, cylinder->direction->y, cylinder->direction->z);
	printf("Radius: %f\n", cylinder->radius);
	printf("Height: %f\n", cylinder->height);
	printf("Color: %d %d %d\n\n", cylinder->color->r, cylinder->color->g, cylinder->color->b);
}
