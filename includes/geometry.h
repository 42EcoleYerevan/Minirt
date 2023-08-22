#ifndef GEOMETRY_H
# define GEOMETRY_H

enum e_figure
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec;

typedef struct s_mat
{
	t_vec	*x;
	t_vec	*y;
	t_vec	*z;
	t_vec	*w;
}				t_mat;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	float	a;
}				t_color;

typedef struct s_ambient
{
	t_color		*color;
	float		brightness;
}				t_ambient;

typedef struct	s_sphere {
	t_vec			*center;
	float			radius;
	int				specular;
}				t_sphere;

typedef struct s_plane
{
	t_vec	*point;
	t_vec	*normal;
	int		specular;
}				t_plane;

typedef struct s_cylinder
{
	t_vec	*center;
	t_vec	*direction;
	float	radius;
	float	height;
	int		specular;
}			t_cylinder;

typedef struct s_light
{
	t_color			*color;
	t_vec			*center;
	float			brightness;
	struct s_light	*next;
}	t_light;

typedef struct	s_camera
{
	t_vec	*origin;
	t_vec	*direction;
	t_vec	*up;
	t_vec	*right;
	float	near;
	float	far;
	float	fov;
}				t_camera;

typedef struct s_figure
{
	int				type;
	t_color			*color;
	void			*data;
	struct s_figure	*next;
}	t_figure;

typedef struct	s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

typedef struct	s_scene
{
	t_figure	*figure;
	t_camera	*cams;
	t_ambient	*ambient;
	t_light		*light;
	float		width;
	float		height;
}				t_scene;

#endif
