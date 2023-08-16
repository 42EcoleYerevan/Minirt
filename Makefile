NAME=a.out
HEADER_DIR=./includes
SRC_DIR=./srcs
SRCS=$(wildcard $(SRC_DIR)/*.c)
SRCS+=$(wildcard $(SRC_DIR)/**/*.c)
OBJS_DIR=./objs
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
LIBFT_DIR=./libft
LIBFT_A=$(LIBFT_DIR)/libft.a
ifeq ($(shell uname), Linux)
	MLX_DIR=./mlx_linux
	MLX_MAKE=cd $(MLX_DIR) && ./configure
	MLX_CLEAN=cd $(MLX_DIR) && ./configure clean
else
	MLX_DIR=./mlx_mac
	MLX_MAKE=@make -C $(MLX_DIR)
	MLX_CLEAN=@make -C $(MLX_DIR) clean
endif
MLX_A=$(MLX_DIR)/libmlx.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBS_FLAG=-L $(LIBFT_DIR) -lft \
			-L $(MLX_DIR) -lmlx \
			-I $(HEADER_DIR)
ifeq ($(shell uname), Linux)
	LIBS_FLAG+=-Imlx_linux \
			   -lXext \
			   -lX11 \
			   -lm \
			   -lz
else
	LIBS_FLAG+=-framework OpenGL \
			   -framework AppKit
endif
# LIBS_FLAG+= -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAG) -o $(NAME)

$(OBJS_DIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -Imlx_linux -O3 -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT_DIR) bonus

$(MLX_A):
	$(MLX_MAKE)

clean:
	rm -rf $(OBJS_DIR)
	# $(MLX_CLEAN)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
