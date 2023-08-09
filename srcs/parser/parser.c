#include "minirt.h"

char **ft_read_file(char *path)
{	
	int fd;
	char *line;
	char **strarr;
	int i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	strarr = NULL;
	i = 0;
	line = ft_readline(fd);
	while (line)
	{
		strarr = ft_arrjoin(strarr, line);
		free(line);
		line = ft_readline(fd);
		printf("%s", strarr[i++]);
	}
	return (NULL);
}

char **ft_tokenizer(char *path)
{
	char **text;

	text = ft_read_file(path);
	return text;
}
