#include "minirt.h"

int	ft_is_valid_extension(char *filename)
{
	filename += ft_strlen(filename) - 3;
	if (ft_strncmp(filename, ".rt", 3) == 0)
		return (0);
	return (1);
}
