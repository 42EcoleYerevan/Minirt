/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:34:59 by almeliky          #+#    #+#             */
/*   Updated: 2023/08/25 15:34:59 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*new_figure(void *data, int type)
{
	t_figure	*new;

	new = malloc(sizeof(t_figure));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->data = data;
	new->type = type;
	new->next = NULL;
	return (new);
}
