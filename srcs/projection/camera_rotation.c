#include "minirt.h"

void	ft_camera_rotate(t_scene *scene, float *matrix)
{
	ft_vec_mult_mat(scene->cams->direction, matrix);
	ft_vec_mult_mat(scene->cams->right, matrix);
	ft_vec_norm(scene->cams->direction);
	ft_vec_norm(scene->cams->right);
}

void	ft_camera_xrotate(t_scene *scene, float angle)
{
	float *xrotate;

	xrotate = ft_xrotation_matrix(angle);
	if (xrotate == NULL)
		return ;
	ft_camera_rotate(scene, xrotate);
	free(xrotate);
}

void ft_camera_yrotate(t_scene *scene, float angle)
{
	float *yrotate;

	yrotate = ft_yrotation_matrix(angle);
	if (yrotate == NULL)
		return ;
	ft_camera_rotate(scene, yrotate);
	free(yrotate);
}

void ft_camera_zrotate(t_scene *scene, float angle)
{
	float *zrotate;

	zrotate = ft_zrotation_matrix(angle);
	if (zrotate == NULL)
		return ;
	ft_camera_rotate(scene, zrotate);
	free(zrotate);
}
