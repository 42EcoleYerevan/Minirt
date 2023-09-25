/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:21:44 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/25 15:45:53 by adamsonbo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	**ft_read_file(char *path);
static int	ft_is_empty_line(char *line);
static void	ft_delete_empty_lines(char **lines);
static void	ft_shift_arr(char **lines, int i);

char	**ft_read_scene(char *path)
{
	char	**text;

	text = ft_read_file(path);
	ft_trim_newline(text);
	ft_delete_empty_lines(text);
	return (text);
}

static void	ft_delete_empty_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_is_empty_line(lines[i]))
		{
			free(lines[i]);
			ft_shift_arr(lines, i);
		}
		i++;
	}
}

static void	ft_shift_arr(char **lines, int i)
{
	while (lines[i])
	{
		lines[i] = lines[i + 1];
		i++;
	}
}

static int	ft_is_empty_line(char *line)
{
	int	i;
	int	isempty;

	i = 0;
	isempty = 1;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			isempty = 0;
			break ;
		}
		i++;
	}
	return (isempty);
}

static char	**ft_read_file(char *path)
{
	int		fd;
	char	*line;
	char	**strarr;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	strarr = NULL;
	line = ft_readline(fd);
	while (line)
	{
		strarr = ft_arrjoin(strarr, line);
		free(line);
		line = ft_readline(fd);
	}
	free(line);
	return (strarr);
}
