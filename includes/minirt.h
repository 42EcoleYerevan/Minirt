#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "./geometry.h"

# ifdef __APPLE__
# define OSFLAG 1
# include "../mlx_mac/mlx.h"
# elif __linux__
# define OSFLAG 2
# include "../mlx_linux/mlx.h"
# endif

# define WIDTH 1000
# define HEIGHT 1000
# define EPSILON 0.001

//shapes
t_vec	ft_get_vector_from_token(char *token);
t_color	*ft_get_color_from_token(char *token);
int		ft_set_ambient(char **tokens, t_scene *scene);
int		ft_set_camera(char **tokens, t_scene *scene);
int		ft_set_sphere(char **tokens, t_scene *scene);
int		ft_set_light(char **tokens, t_scene *scene);
int		ft_set_plane(char **tokens, t_scene *scene);
int		ft_set_cylinder(char **tokens, t_scene *scene);

//shapes
void	ft_add_figure(t_scene *scene, t_figure *figure);

// validator
int		ft_is_valid_extension(char *filename);
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
t_vec	ft_vec_mult(t_vec vec, float mult);
float	ft_vec_len(t_vec vec);
t_vec	ft_vec_substr(t_vec vec1, t_vec vec2);
t_vec	ft_vec_add(t_vec vec1, t_vec vec2);
t_vec	ft_vec_norm(t_vec vec);
float	ft_vec_mult_dot(t_vec vec1, t_vec vec2);
float	ft_vec_dist(t_vec v1, t_vec v2);
t_vec	ft_vec_dup(t_vec vec);
t_vec	ft_vec_cross(t_vec vec1, t_vec vec2);

void	err_exit(char *str);

// utils/color
int		get_color(int red, int green, int blue, float bright);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);

// geometry init
t_vec		new_4vector(float x, float y, float z, float w);
t_vec		new_zero_vec(void);
t_vec		new_vector(float x, float y, float z);
t_figure	*new_sphere(t_vec vec, float radius, t_color *color);
t_figure	*new_cylinder(t_vec center, t_vec direction, float radius_height[2], t_color *color);
t_camera	*new_camera(t_vec origin, t_vec direction, float fov);
t_scene		*new_scene(float width, float height);
t_light		*new_light(t_vec center, float brightness, t_color *color);
t_vplane	*new_vplane(float width, float height, float fov);
t_ambient	*new_ambient(t_color *color, float brightness);
t_color		*new_color(int r, int g, int b, float a);
t_vec		normal_check_and_reverse(t_vec normal);
t_figure	*new_plane(t_vec center, t_vec direction, t_color *color);
t_figure	*new_figure(void *data, int type);
void		ft_init_hooks(t_scene *scene);
t_matrix	ft_new_zero_matrix(void);
t_matrix	ft_identity_matrix(void);

// ray tracing
float		sphere_inter(t_vec o, t_vec ray, t_sphere *sphere);
float		plane_inter(t_vec o, t_vec d, t_vec point, t_vec normal);
float		cylinder_inter(t_vec o, t_vec d, t_figure *figure);
void		scene_render(t_scene *scene, int mlx_x, int mlx_y);
int			ray_trace(t_scene *scene);
float		closest_inter(t_figure *figure, t_figure **obj, t_vec o, t_vec d);
t_vec		create_sphere_norm(t_vec p, t_vec center);
t_vec		new_vec_obj_cross(t_scene *scene, t_figure **obj);

// light calculation
float		calc_light(t_vec p, t_scene *scene, t_figure *figure);
float		calc_specular(t_scene *scene, t_light *light, t_figure *figure);
float		cacl_diffuse(t_vec l, t_vec n, t_light *light);
int			check_shadow(t_scene *scene, t_light **light, t_vec p);

// print
void	ft_print_scene(t_scene *scene);
void	ft_print_sphere(t_figure *figure);
void	ft_print_plane(t_figure *figure);
void	ft_print_cylinder(t_figure *figure);
void	ft_print_vec(t_vec vec);

// controller
void	ft_mouse_scroll_hook(int keycode, t_scene *scene);
int		ft_mousedown_hook(int keycode, int x, int y, t_scene *scene);
int		ft_mouseup_hook(int keycode, int x, int y, t_scene *scene);
int		ft_mousemove_hook(int x, int y, t_scene *scene);
int		key_hook(int keycode, t_scene *scene);

// render
int render(void *scene);

// matrix_act
t_matrix	ft_mat_mult(t_matrix mat1, t_matrix mat2);
t_matrix	ft_mat_sub(t_matrix mat1, t_matrix mat2);
t_matrix	ft_mat_add(t_matrix mat1, t_matrix mat2);
t_vec		ft_vec_mult_mat(t_vec vec, t_matrix mat);

// projection
float	*ft_view_matrix(t_camera *camera);
void	ft_move_scene_to_camera(t_scene *scene, t_camera *camera);

// rotation
t_matrix	ft_xrotate_matrix(float angle);
t_matrix	ft_yrotate_matrix(float angle);
t_matrix	ft_zrotate_matrix(float angle);
void		ft_rotate_objects(t_scene *scene, t_matrix matrix);

// move
void	ft_xrotate_scene(t_scene *scene, float angle);
void	ft_yrotate_scene(t_scene *scene, float angle);
void	ft_zrotate_scene(t_scene *scene, float angle);
void	ft_xmove_scene(t_scene *scene, float step);
void	ft_ymove_scene(t_scene *scene, float step);
void	ft_zmove_scene(t_scene *scene, float step);
void	ft_move_obj(t_scene *scene, t_vec vector);

// render 
int		render(void *scene);
void	ft_put_pixel(t_scene *scene, int x, int y, int color);

#endif
