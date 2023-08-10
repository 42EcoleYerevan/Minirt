/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:28:37 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/10 11:48:04 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_arrlen(char **arr);
void		ft_free_arr(char **arr);
static void	ft_arrcpy(char **dest_arr, char **src_arr);

char	**ft_arrjoin(char **arr, char *str)
{
	char	**new_arr;
	int		len;

	len = ft_arrlen(arr);
	new_arr = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_arr)
		return (NULL);
	ft_arrcpy(new_arr, arr);
	free(arr);
	if (!new_arr)
		return (NULL);
	new_arr[len] = ft_strdup(str);
	if (!new_arr[len])
	{
		ft_free_arr(new_arr);
		return (NULL);
	}
	new_arr[len + 1] = NULL;
	return (new_arr);
}

static void ft_arrcpy(char **dest_arr, char **src_arr)
{
	int i;

	if (!src_arr)
	{
		dest_arr[0] = NULL;
		return ;
	}
	i = 0;
	while (src_arr[i])
	{
		dest_arr[i] = src_arr[i];
		i++;
	}
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

void ft_print_2d_array(char **arr)
{
	if (!arr)
		return ;
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}
