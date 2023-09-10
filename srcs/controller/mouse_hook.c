 #include "minirt.h"

void	ft_mouse_scroll_hook(int keycode, t_scene *scene)
{
	printf("mouse scroll %d\n", keycode);
	if (keycode == 4)
		scene->cams->origin.z -= 10;
	else if (keycode == 5)
		scene->cams->origin.z += 10;
}

int	ft_mousedown_hook(int keycode, int x, int y, t_scene *scene)
{
	t_vec		d;
	t_figure	*f;
	float x_angle;
	float y_angle;

	printf("mouse down %d\n", keycode);
	printf("x: %d, y: %d\n", x, y);
	f = NULL;
	scene->button = keycode;
	if (keycode == 1)
	{

		y_angle = (scene->height / 2 + 1) - y;
		x_angle = ((scene->width / 2) * (-1) - 1) + x;
		printf("x_angle: %f, y_angle: %f\n", x_angle, y_angle);
		d = new_4vector(x_angle * scene->vplane->x_pixel, \
				y_angle * scene->vplane->y_pixel, -1, 1);
		d = ft_vec_norm(d);
		ft_print_vec(d);
		closest_inter(scene->figure, &f, scene->cams->origin, d);
		if (!f)
		{
			puts("no figure");
			return (0);
		}
		printf("%d\n", f->type);
	}
	ft_mouse_scroll_hook(keycode, scene);
	return (0);
}

int ft_mouseup_hook(int keycode, int x, int y, t_scene *scene)
{
	printf("mouse up %d\n", keycode);
	(void)scene;
	(void)keycode;
	(void)x;
	(void)y;
	scene->button = -1;
	return (0);
}

int ft_mousemove_hook(int x, int y, t_scene *scene)
{
	static int old_x = 0;
	static int old_y = 0;

	if (scene->button == 1 && old_x != 0 && old_y != 0)
	{
		/* scene->cams->origin->x -= x - old_x; */
		/* scene->cams->origin->y += y - old_y; */
		scene->cams->direction.x -= x - old_x;
		scene->cams->direction.y += y - old_y;
		ft_vec_norm(scene->cams->direction);
	}
	old_x = x;
	old_y = y;
	return (0);
}
