/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:28:37 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/09 19:42:18 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	**ft_arrdup(char **dest_arr, char **src_arr);
int			ft_arrlen(char **arr);
void		ft_free_arr(char **arr);

char	**ft_arrjoin(char **arr, char *str)
{
	char	**new_arr;
	int		len;

	len = ft_arrlen(arr);
	new_arr = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_arr)
		return (NULL);
	new_arr = ft_arrdup(new_arr, arr);
	if (!new_arr)
		return (NULL);
	new_arr[len] = ft_strdup(str);
	if (!new_arr[len])
	{
		ft_free_arr(new_arr);
		return (NULL);
	}
	new_arr[len + 1] = NULL;
	ft_free_arr(arr);
	return (new_arr);
}

static char **ft_arrdup(char **dest_arr, char **src_arr)
{
	int		i;

	i = 0;
	if (!src_arr)
	{
		dest_arr[0] = NULL;
		return (dest_arr);
	}
	while (src_arr[i])
	{
		dest_arr[i] = ft_strdup(src_arr[i]);
		if (!dest_arr[i])
		{
			ft_free_arr(dest_arr);
			return (NULL);
		}
		i++;
	}
	dest_arr[i] = NULL;
	return (dest_arr);
}

int	ft_arrlen(char **arr)
{
	int i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free_arr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
