#include "minirt.h"

int main()
{
	t_scene *scene;

	scene = NULL;
	ft_parser("scenes/leha.rt", scene);
	return (0);
}
