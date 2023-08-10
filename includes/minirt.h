#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../includes/shapes.h"

# define WIDTH 300
# define HEIGHT 300

// parser
int		ft_parser(char *filename, t_rt *rt);

// readline
char	*ft_readline(int fd);

// parser arr utils
int		ft_arrlen(char **arr);
void	ft_free_arr(char **arr);
char	**ft_arrjoin(char **arr, char *str);
void	ft_print_2d_array(char **arr);

//parser tokenizer
char	**ft_tokenizer(char *path);

// parser map
int		ft_parse_map(char **lines);

// parser shapes
int	ft_set_shapes(char **tokens);

// init
t_rt	*ft_new_rt(int width, int height, char *title);
t_camera *ft_new_camera(t_vec center, t_vec norm, float fov);
t_light *ft_new_light(t_vec center, \
					t_vec norm, \
					float brightness, \
					t_color color);
t_plane *ft_new_plane(t_vec center, t_vec norm, t_color color);
t_sphere *ft_new_sphere(t_vec center, float radius, t_color color);
t_cylinder *ft_new_cylinder(t_vec center, \
							t_vec norm, \
							float values[2], \
							t_color color);

#endif
