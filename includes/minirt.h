#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "./geometry.h"

# define WIDTH 300
# define HEIGHT 300

// parser
int		ft_parser(char *filename, t_scene *scene);

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
int		ft_parse_map(char **lines, t_scene *scene);

// parser shapes
int		ft_set_shape(char **tokens, t_scene *scene);

// math
void	ft_vec_mult(t_vec *vec, float mult);
void	ft_vec_mult_vec(t_vec *vec1, t_vec *vec2);
void	ft_vec_mult_mat(t_vec *vec, t_mat *mat);
void	ft_mat_mult_mat(t_mat *mat1, t_mat *mat2);

t_vec	*vec_substr(t_vec *vec1, t_vec *vec2);
float	vec_len(t_vec *vec);
void	vec_norm(t_vec *vec);
float	vec_mult_dot(t_vec *vec1, t_vec *vec2);

void	err_exit(char *str);

t_vec		*new_vector(float x, float y, float z);
t_sphere	*new_sphere(t_vec *vec, float radius);
t_camera	*new_camera(t_vec *origin, t_vec *direction, float fov);
t_scene		*new_scene(t_camera *cam, t_sphere *sphere);
t_vplane	*get_new_vplane(float width, float height, float fov);

float		sphere_inter(t_camera *cam, t_vec *ray, t_sphere *sphere);
void		ray_tracing(void *mlx, void *win, t_scene *scene);

#endif
