NAME=minirt
HEADER_DIR=./includes
SRC_DIR=./srcs
SRCS=$(wildcard $(SRC_DIR)/**/*.c)
OBJS_DIR=./objs
OBJS=$(SRCS:%.c=$(OBJS_DIR)/%.o)
LIBFT_DIR=./libft
LIBFT_A=$(LIBFT_DIR)/libft.a
MLX_DIR=./minilibx
MLX_A=$(MLX_DIR)/libmlx.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(HEADER_DIR) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean: 
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
