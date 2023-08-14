#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifdef __APPLE__
# include "../mlx_mac/mlx.h"
# elif __linux__
# include "../mlx_linux/mlx.h"
# endif
# include "./geometry.h"

# define WIDTH 300
# define HEIGHT 300

//shapes
t_vec	*ft_get_vector_from_token(char *token);
t_color	*ft_get_color_from_token(char *token);
int		ft_set_ambient(char **tokens, t_scene *scene);
int		ft_set_camera(char **tokens, t_scene *scene);

// validator
int		ft_validator(char **lines);
int		ft_is_valid_float(char *str);
int		ft_is_valid_ambient(char **tokens);
int		ft_is_valid_cam(char **lines);
int		ft_is_valid_num_of_cams(char **lines);
int		ft_is_valid_color(char *str);
int		ft_is_valid_vector(char *str);
int		ft_is_valid_fov(char *str);
int		ft_is_valid_direction(char *str);
int		ft_is_valid_light(char **tokens);
int		ft_is_valid_sphere(char **tokens);
int		ft_is_valid_plane(char **tokens);
int		ft_is_valid_cylinder(char **tokens);

// parser
int		ft_parser(char *filename, t_scene *scene);
char	**ft_split_line(char *line);

// parser utils
float	ft_atof(char *str);
int		ft_str_to_int(char *str);
int		ft_len_after_dot(char *str);
int		ft_len_before_dot(char *str);
float	ft_str_to_int_part(char *str);
float	ft_str_to_decimal_part(char *str);
void	ft_trim_newline(char **lines);

// readline
char	*ft_readline(int fd);

// parser arr utils
int		ft_arrlen(char **arr);
void	ft_free_arr(char **arr);
char	**ft_arrjoin(char **arr, char *str);
void	ft_print_2d_array(char **arr);

//parser tokenizer
char	**ft_read_scene(char *path);

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

t_color		*new_color(int r, int g, int b, float a);
t_ambient	*new_ambient(t_color *color, float ratio);
t_plane		*new_plane(t_vec *center, t_vec *direction, t_color *color);
t_vec		*new_vector(float x, float y, float z);
t_sphere	*new_sphere(t_vec *vec, float radius);
t_camera	*new_camera(t_vec *origin, t_vec *direction, float fov);
t_scene		*new_scene(float width, float height);
t_vplane	*get_new_vplane(float width, float height, float fov);

float		sphere_inter(t_camera *cam, t_vec *ray, t_sphere *sphere);
void		ray_tracing(void *mlx, void *win, t_scene *scene);

#endif
