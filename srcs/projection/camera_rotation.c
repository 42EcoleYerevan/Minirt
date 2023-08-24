#include "minirt.h"

void	ft_camera_rotate(t_camera *camera, float *matrix)
{
	ft_vec_mult_mat(camera->direction, matrix);
	ft_vec_mult_mat(camera->right, matrix);
	ft_vec_norm(camera->direction);
	ft_vec_norm(camera->right);
}

void	ft_camera_xrotate(t_camera *camera, float angle)
{
	float *xrotate;

	xrotate = ft_xrotation_matrix(angle);
	if (xrotate == NULL)
		return ;
	ft_camera_rotate(camera, xrotate);
	free(xrotate);
}

void ft_camera_yrotate(t_camera *camera, float angle)
{
	float *yrotate;

	yrotate = ft_yrotation_matrix(angle);
	if (yrotate == NULL)
		return ;
	ft_camera_rotate(camera, yrotate);
	free(yrotate);
}

void ft_camera_zrotate(t_camera *camera, float angle)
{
	float *zrotate;

	zrotate = ft_zrotation_matrix(angle);
	if (zrotate == NULL)
		return ;
	ft_camera_rotate(camera, zrotate);
	free(zrotate);
}
