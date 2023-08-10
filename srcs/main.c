#include "minirt.h"

int main()
{
	t_rt *rt;

	rt = ft_new_rt(WIDTH, HEIGHT, "miniRT");
	if (!rt)
		return (1);
	ft_parser("scenes/leha.rt", rt);
	return (0);
}
