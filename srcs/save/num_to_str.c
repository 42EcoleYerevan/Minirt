/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:31:32 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 17:32:10 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_rgb_to_str(t_color *color)
{
	int	n;

	n = color->r >> 16;
	n += color->g >> 8;
	n += color->b;
	return (ft_itohex(n));
}

char	*ft_ftoa(float n)
{
	char	*out;

	out = "";
	out = ft_strjoin(out, ft_itoa((int)n));
	out = ft_strjoin(out, ".");
	if (n < 0)
		n *= -1;
	n -= (int)n;
	n *= 10000;
	out = ft_strjoin(out, ft_itoa((int)n));
	return (out);
}

char	*ft_itohex(int n)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * 9);
	if (!str)
		err_exit("Error\n\tMalloc error");
	str[0] = '0';
	str[1] = 'x';
	i = 2;
	while (i < 9)
	{
		str[i] = base[n % 16];
		i++;
		n /= 16;
	}
	return (str);
}
