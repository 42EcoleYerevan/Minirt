#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIDTH 300
# define HEIGHT 300

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct s_mat {
	t_vec	x;
	t_vec	y;
	t_vec	z;
	t_vec	w;
} t_mat;

// parser
int ft_parser(char *filename);

// readline
char	*ft_readline(int fd);

// parser arr utils
int		ft_arrlen(char **arr);
void	ft_free_arr(char **arr);
char	**ft_arrjoin(char **arr, char *str);
void	ft_print_2d_array(char **arr);

//parser tokenizer
char **ft_tokenizer(char *path);

// parser map
int ft_parse_map(char **lines);

#endif
