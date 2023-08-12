#include "minirt.h"

int	ft_is_valid_num_of_cams(char **lines)
{
	char	**tokens;
	int		n;
	int		ncams;

	n = 0;
	ncams = 0;
	while (lines[n])
	{
		tokens = ft_split_line(lines[n]);
		if (tokens && ft_strncmp(tokens[0], "C", 2) == 0)
			ncams++;
		ft_free_arr(tokens);
		n++;
	}
	if (ncams != 1)
		return (1);
	return (0);
}

int	ft_is_valid_cam(char **tokens)
{
	if (ft_arrlen(tokens) != 4)
		return (1);
	if (ft_is_valid_vector(tokens[1]) || \
		ft_is_valid_direction(tokens[2]) || \
		ft_is_valid_fov(tokens[3]))
		return (1);
	return (0);
}
