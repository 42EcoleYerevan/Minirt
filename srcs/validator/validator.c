#include "minirt.h"

int	ft_validate_args(char **tokens);

int	ft_validator(char **lines)
{
	int n;
	char **tokens;

	ft_is_valid_num_of_cams(lines);
	n = 0;
	while (lines[n])
	{
		tokens = ft_split_line(lines[n]);
		if (!tokens)
			return (1);
		if (ft_validate_args(tokens))
			return (1);
		ft_free_arr(tokens);
		n++;
	}
	return (0);
}

int	ft_validate_args(char **tokens)
{
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return ft_is_valid_ambient(tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return ft_is_valid_cam(tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return ft_is_valid_light(tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return ft_is_valid_sphere(tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return ft_is_valid_plane(tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return ft_is_valid_cylinder(tokens);
	else
		return (1);
}
