#include "minirt.h"

void ft_print_2d_array(char **arr)
{
	if (!arr)
		return ;
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

int main()
{
	/* void *mlx; */
	/* void *img; */
	/* void *win; */

	/* mlx = mlx_init(); */
	/* img = mlx_new_image(mlx, WIDTH, HEIGHT); */
	/* win = mlx_new_window(mlx, WIDTH, HEIGHT, "Minirt"); */
	/* mlx_put_image_to_window(mlx, win, img, 0, 0); */
	/* mlx_loop(mlx); */

	char **tokens = ft_tokenizer("./scenes/leha.rt");
	ft_print_2d_array(tokens);
	return (0);
}
