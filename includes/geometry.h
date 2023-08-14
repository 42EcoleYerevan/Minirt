#ifndef GEOMETRY_H
# define GEOMETRY_H

enum e_figure
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct s_mat
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
	t_vec	w;
} t_mat;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	float	a;
}	t_color;

typedef struct s_ambient
{
	t_color	*color;
	float	brightness;
}	t_ambient;

typedef struct	s_sphere {
	int		color;
	t_vec	*center;
	float	radius;
	struct	s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	int		color;
	t_vec	*center;
	t_vec	*direction;
	struct	s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	int		color;
	t_vec	*center;
	t_vec	*direction;
	float	radius;
	float	height;
	struct	s_cylinder	*next;
}	t_cylinder;

typedef struct s_light
{
	int		color;
	t_vec	*center;
	float	brightness;
}	t_light;

typedef struct	s_camera
{
	t_vec	*origin;
	t_vec	*direction;
	float	fov;
}				t_camera;

<<<<<<< HEAD
typedef struct	s_ambient
{
	int		color;
	float	bright;
}			t_ambient;
=======
typedef struct s_figure
{
	int				type;
	void			*figure;
	struct s_figure	*next;
}	t_figure;
>>>>>>> bdd215f8697b125e936f9aa6923b8fbe091ade81

typedef struct	s_scene
{
	t_figure	*figure;
	t_camera	*cams;
<<<<<<< HEAD
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_light		*light;
	t_ambient	*ambient;
=======
	t_ambient	*ambient;
	t_light		*light;
>>>>>>> bdd215f8697b125e936f9aa6923b8fbe091ade81
	float		width;
	float		height;
}				t_scene;

typedef struct	s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

#endif
