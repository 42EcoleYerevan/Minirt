#include "minirt.h"

void ft_text_render(t_scene *scene);
void ft_draw_rect_fill(t_scene *scene, t_vec *rect, int color);

int render(void *scene)
{
	t_scene		*tscene;

	tscene = (t_scene *)scene;
	tscene->vplane = new_vplane(tscene->width, tscene->height, tscene->cams->fov);
    scene_render(tscene, 0, 0);
	if (tscene->ui == 1)
		ft_text_render(tscene);
	return (0);
}

void ft_text_render(t_scene *scene)
{
	char *string[10];
	int i;
	int step;

	string[0] = "Key: ";
	string[1] = "WASD - xy rotate";
	string[2] = "QE - z rotate";
	string[3] = "ZX - y move";
	string[4] = "arrows - move";
	string[5] = "ESC - exit";
	string[6] = "Show / Hide UI: U";
	if (scene->button != -1)
		string[7] = ft_strjoin("Button: ", ft_itoa(scene->button));
	else
		string[7] = NULL;
	printf("%d\n", scene->button);
	string[8] = NULL;

	ft_draw_rect_fill(scene, new_4vector(0, 0, 200, HEIGHT), 0x333333);
	i = 0;	
	step = 20;
	while (string[i])
	{
		mlx_string_put(scene->mlx, scene->win, step, step + i * step, 0x00FFFFFF, string[i]);
		i++;
	}
}

void ft_draw_rect_fill(t_scene *scene, t_vec *rect, int color)
{
	int x;
	int y;

	x = rect->x;
	while (x < rect->x + rect->z)
	{
		y = rect->y;
		while (y < rect->y + rect->w)
		{
			mlx_pixel_put(scene->mlx, scene->win, x, y, color);
			y++;
		}
		x++;
	}
}
