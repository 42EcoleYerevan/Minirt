#include "minirt.h"

void	err_exit(char *str)
{
    int val;

	while(*str)
		val = write(2, str++, 1);
    (void)val;
    exit(1);
}
