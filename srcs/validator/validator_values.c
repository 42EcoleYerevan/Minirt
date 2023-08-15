#include "minirt.h"

int	ft_is_valid_color(char *str)
{
	char	**fnumbers;
	float	color;
	int		status;
	int		n;

	status = 0;
	fnumbers = ft_split(str, ',');
	if (!fnumbers)
		status = 1;
	if (ft_arrlen(fnumbers) != 3)
		status = 1;
	n = 0;
	while (n < 3)
	{
		color = ft_atof(fnumbers[n]);
		if (color < 0.0 || color > 255.0)
			status = 1;
		n++;
	}
	ft_free_arr(fnumbers);
	return (status);
}

int	ft_is_valid_vector(char *str)
{
	char	**fnumbers;
	int		n;
	int		status;

	status = 0;
	if (!str)
		status = 1;
	fnumbers = ft_split(str, ',');
	if (!fnumbers)
		status = 1;
	if (ft_arrlen(fnumbers) != 3)
		status = 1;
	n = 0;
	while (n < 3)
	{
		if (ft_is_valid_float(fnumbers[n]))
			status = 1;
		n++;
	}
	ft_free_arr(fnumbers);
	return (status);
}

int	ft_is_valid_fov(char *str)
{

	float fov;

	fov = ft_atof(str);
	if (fov < 0.0 || fov > 180.0)
		return (1);
	return (0);
}

int	ft_is_valid_direction(char *str)
{
	char	**fnumbers;
	int		status;

	status = 0;
	fnumbers = ft_split(str, ',');
	puts(str);
	printf("%f ", ft_atof(fnumbers[0]));
	printf("%f ", ft_atof(fnumbers[1]));
	printf("%f\n", ft_atof(fnumbers[2]));
	if (!fnumbers)
		status = 1;
	if (ft_arrlen(fnumbers) != 3)
		status = 1;
	if (ft_atof(fnumbers[0]) < -1.0 || ft_atof(fnumbers[0]) > 1.0)
		status = 1;
	if (ft_atof(fnumbers[1]) < -1.0 || ft_atof(fnumbers[1]) > 1.0)
		status = 1;
	if (ft_atof(fnumbers[2]) < -1.0 || ft_atof(fnumbers[2]) > 1.0)
		status = 1;
	ft_free_arr(fnumbers);
	return (status);
}
