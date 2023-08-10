#ifndef SHAPES_H
# define SHAPES_H

enum eshape
{
	SPHERE,
	PLANE,
	CYLINDER,
};

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct s_mat {
	t_vec	x;
	t_vec	y;
	t_vec	z;
	t_vec	w;
}	t_mat;

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
	float	alpha;
}	t_color;

typedef struct s_ambient
{
	t_color	color;
	float	brightness;
}	t_ambient;

typedef struct s_camera
{
	t_vec	center;
	t_vec	norm;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_color 		color;
	t_vec			center;
	t_vec			norm;
	float			brightness;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	t_color			color;
	t_vec			center;
	int				shape;
	float			radius;
	void			*next;
}	t_sphere;

typedef struct s_plane
{
	t_color			color;
	t_vec			center;
	t_vec			norm;
	int				shape;
	void			*next;
}	t_plane;

typedef struct s_cylinder
{
	t_color				color;
	t_vec				center;
	t_vec				norm;
	void				*next;
	float				radius;
	float				height;
	int					shape;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*lights;
	void		*shapes;
}	t_scene;

typedef struct s_rt
{
	int		width;
	int		height;
	char	*title;
	void	*mlx;
	void	*win;
	void	*img;
	t_scene *scene;
}	t_rt;

#endif
