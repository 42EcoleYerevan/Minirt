#include "minirt.h"

int main()
{
	void *mlx;
	void *img;
	void *win;

	mlx = mlx_init();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Minirt");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	printf("Hello World!\n");
	return (0);
}
