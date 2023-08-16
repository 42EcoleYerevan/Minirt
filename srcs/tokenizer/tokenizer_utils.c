#include "minirt.h"

void ft_trim_newline(char **lines)
{
	int		n;
	char	*tmp;

	n = 0;
	while (lines[n])
	{
		tmp = lines[n]; 
		lines[n] = ft_strtrim(lines[n], "\n");
		free(tmp);
		n++;
	}
}
