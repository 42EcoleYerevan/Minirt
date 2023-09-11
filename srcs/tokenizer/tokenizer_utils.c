/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:20:53 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:20:54 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_trim_newline(char **lines)
{
	int		n;
	char	*tmp;

	n = 0;
	while (lines[n])
	{
		tmp = lines[n];
		lines[n] = ft_strtrim(lines[n], "\n\r\t\v\f");
		free(tmp);
		n++;
	}
}
