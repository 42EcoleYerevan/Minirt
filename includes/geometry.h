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
}	t_vec;

typedef struct s_matrix
{
	float	m[16];
}	t_matrix;

typedef struct	s_abc
{
	float	a;
	float	b;
	float	c;
	float	disc;
}	t_abc;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	float	a;
}	t_color;

typedef struct s_ambient
{
	t_color		*color;
	float		brightness;
}	t_ambient;

typedef struct	s_sphere {
	t_vec			center;
	float			radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec	point;
	t_vec	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	center;
	t_vec	direction;
	float	radius;
	float	height;
	float	dist[2];
}	t_cylinder;

typedef struct s_light
{
	t_color			*color;
	t_vec			center;
	float			brightness;
	struct s_light	*next;
}	t_light;

typedef struct	s_camera
{
	t_vec	origin;
	t_vec	direction;
	t_vec	right;
	float	near;
	float	far;
	float	fov;
}	t_camera;

typedef struct s_figure
{
	t_vec			normal;
	t_color			*color;
	void			*data;
	int				specular;
	int				type;
	struct s_figure	*next;
}	t_figure;

typedef struct	s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}	t_vplane;

typedef struct	s_scene
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_figure	*figure;
	t_camera	*cams;
	t_ambient	*ambient;
	t_light		*light;
	t_vplane	*vplane;
	t_vec		vecs[3];
	float		width;
	float		height;
	int 		button;
	float 		x_angle;
	float 		y_angle;
	float 		z_angle;
	float		xmove;
	float		ymove;
	float		zmove;
	int			ui;
}	t_scene;

#endif
