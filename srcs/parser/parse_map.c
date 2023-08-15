#include "minirt.h"

static int	ft_len_spaces(char *line);
static int	ft_len_token(char *line);
static int	ft_len_tokens(char *line);
char		**ft_split_line(char *line);

int ft_parse_map(char **lines, t_scene *scene)
{
	int		i;
	char	**tokens;

	i = 0;
	while (lines[i])
	{
		tokens = ft_split_line(lines[i]);
		if (!tokens)
			return (1);
		if (ft_set_shape(tokens, scene))
			return (1);
		ft_free_arr(tokens);
		i++;
	}
	return (0);
}

char	**ft_split_line(char *line)
{
	char	**tokens;
	int		i;

	tokens = (char **)malloc(sizeof(char *) * (ft_len_tokens(line) + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (*line)
	{
		line += ft_len_spaces(line);
		tokens[i] = ft_substr(line, 0, ft_len_token(line));
		if (!tokens[i])
		{
			ft_free_arr(tokens);
			return (NULL);
		}
		i++;
		line += ft_len_token(line);
	}
	tokens[i] = NULL;
	return tokens;
}

static int	ft_len_spaces(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	return (i);
}

static int	ft_len_token(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i])
		i++;
	return (i);
}

static int	ft_len_tokens(char *line)
{
	int num;

	num = 0;
	line += ft_len_spaces(line);
	while (*line)
	{
		line += ft_len_token(line);
		num++;
		line += ft_len_spaces(line);
	}
	return (num);
}
