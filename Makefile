NAME=a.out
HEADER_DIR=./includes
SRC_DIR=./srcs
SRCS=$(wildcard $(SRC_DIR)/*.c)
SRCS+=$(wildcard $(SRC_DIR)/**/*.c)
OBJS_DIR=./objs
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
LIBFT_DIR=./libft
LIBFT_A=$(LIBFT_DIR)/libft.a
MLX_DIR=./mlx_linux
MLX_A=$(MLX_DIR)/libmlx.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBS_FLAG=-L $(LIBFT_DIR) -lft \
		  -L $(MLX_DIR) -lmlx \
		  -framework OpenGL \
		  -framework AppKit \
		  # -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_DIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -Imlx_linux -O3 -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT_DIR) bonus

$(MLX_A):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS_DIR)
	# make -C $(MLX_DIR) clean
	# make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	# rm -f $(MLX_A)
	# rm -f $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re