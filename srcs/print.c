#include "minirt.h"

void	ft_print_scene(t_scene *scene)
{
	t_figure *figure;

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
	printf("Center: %f %f %f\n", plane->center->x, plane->center->y, plane->center->z);
	printf("Direction: %f %f %f\n", plane->direction->x, plane->direction->y, plane->direction->z);
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
