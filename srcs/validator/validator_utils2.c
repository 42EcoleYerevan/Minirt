/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:56:33 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:00:37 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_str_to_int_part(char *str)
{
	float	result;
	int		i;

	result = 0.0;
	i = 0;
	while (str[i] && str[i] != '.')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	return (result);
}

float	ft_str_to_decimal_part(char *str)
{
	int		i;
	float	result;

	i = 0;
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	result = 0.0f;
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
		i++;
	}
	while (i--)
		result /= 10;
	return (result);
}

int	ft_len_before_dot(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

int	ft_len_after_dot(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != '.')
		str++;
	if (!*str)
		return (0);
	str++;
	while (*str++)
		i++;
	return (i);
}
