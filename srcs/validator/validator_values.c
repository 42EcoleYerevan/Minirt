#include "minirt.h"

int	ft_is_valid_color(char *str)
{
	char **fnumbers;
	float r;
	float g;
	float b;

	fnumbers = ft_split(str, ',');
	if (!fnumbers)
		return (1);
	if (ft_arrlen(fnumbers) != 3)
		return (1);
	r = ft_atof(fnumbers[0]);
	g = ft_atof(fnumbers[1]);
	b = ft_atof(fnumbers[2]);
	if (r < 0.0 || r > 255.0)
		return (1);
	if (g < 0.0 || g > 255.0)
		return (1);
	if (b < 0.0 || b > 255.0)
		return (1);
	ft_free_arr(fnumbers);
	return (0);
}

int	ft_is_valid_vector(char *str)
{
	char	**fnumbers;
	int		n;

	if (!str)
		return (1);
	fnumbers = ft_split(str, ',');
	if (!fnumbers)
		return (1);
	if (ft_arrlen(fnumbers) != 3)
		return (1);
	n = 0;
	while (n < 3)
	{
		if (ft_is_valid_float(fnumbers[n]))
			return (1);
		n++;
	}
	ft_free_arr(fnumbers);
	return (0);
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
	char **fnumbers;

	fnumbers = ft_split(str, ',');
	if (!fnumbers)
		return (1);
	if (ft_arrlen(fnumbers) != 3)
		return (1);
	if (ft_atof(fnumbers[0]) < -1.0 || ft_atof(fnumbers[0]) > 1.0)
		return (1);
	if (ft_atof(fnumbers[1]) < -1.0 || ft_atof(fnumbers[1]) > 1.0)
		return (1);
	if (ft_atof(fnumbers[2]) < -1.0 || ft_atof(fnumbers[2]) > 1.0)
		return (1);
	ft_free_arr(fnumbers);
	return (0);
}
