/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:20:53 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 18:02:58 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_trim_newline(char **lines)
{
	int		n;
	char	*tmp;

	n = 0;
	if (!lines)
		err_exit("The file is empty\n");
	while (lines && lines[n])
	{
		tmp = lines[n];
		lines[n] = ft_strtrim(lines[n], "\n\r\t\v\f");
		free(tmp);
		n++;
	}
}
