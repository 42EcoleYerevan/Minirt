#include "minirt.h"

void	err_exit(char *str)
{
	while(*str)
		write(2, str++, 1);
	exit(1);
}
