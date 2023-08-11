#include "minirt.h"

static int ft_is_valid_str_float(char *str);

float	ft_atof(char *str)
{
	float	result;
	int		sign;

	if (ft_is_valid_float(str))
		err_exit("Error: invalid float\n");
	if (!str)
		return (0.0);
	result = 0.0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	result = ft_str_to_int_part(str);
	result += ft_str_to_decimal_part(str);
	return (result * sign);
}

int	ft_is_valid_float(char *str)
{
	int	i;

	if (ft_is_valid_str_float(str))
		return (1);
	while (*str && *str != '.')
		str++;
	i = 0;
	while (*str && *str == '.')
	{
		i++;
		str++;
	}
	if (i > 1)
		return (1);
	return (0);
}

static int ft_is_valid_str_float(char *str)
{
	int			i;
	const char	*tmp = "1234567890.";

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(tmp, str[i]))
			return (1);
		i++;
	}
	return (0);
}
