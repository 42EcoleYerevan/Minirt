#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct	s_sphere {
	t_vec	*center;
	float	radius;
}				t_sphere;

typedef struct	s_camera
{
	t_vec	*origin;
	t_vec	*direction;
	float	fov;
}				t_camera;

typedef struct	s_scene
{
	t_camera	*cams;
	t_sphere	*sphere;
	float		width;
	float		height;
}				t_scene;

typedef struct s_mat
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
	t_vec	w;
} t_mat;

#endif // !1