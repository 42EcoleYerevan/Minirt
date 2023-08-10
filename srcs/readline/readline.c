/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:57:04 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/10 11:40:29 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*ft_bufferjoin(char *buffer, char *buf)
{
	char	*tmp;

	if (!buffer)
		buffer = ft_strdup("");
	tmp = buffer;
	buffer = ft_strjoin(buffer, buf);
	free(tmp);
	return (buffer);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	buf[101];
	int		len;

	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, 100);
		buf[len] = '\0';
		if ((len == 0 && !buffer) || len < 0)
			return (NULL);
		buffer = ft_bufferjoin(buffer, buf);
		if (ft_strchr(buffer, '\n'))
			return (buffer);
	}
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;

	if (!buffer)
		return (NULL);
	line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	return (line);
}

static char	*ft_rebuffer(char *buffer)
{
	char	*tmp;

	if (!buffer)
		return (NULL);
	tmp = buffer;
	buffer = ft_substr(buffer, \
			ft_strchr(buffer, '\n') - buffer + 1, \
			ft_strlen(buffer));
	if (!buffer || ft_strlen(buffer) == 0)
	{
		if (buffer)
			free(buffer);
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (buffer);
}

char	*ft_readline(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
		return (NULL);
	buffer = ft_rebuffer(buffer);
	return (line);
}
