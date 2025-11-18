NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lm -lXext -lX11
INCLUDES	= -I. -I./libft -I./includes

MLX_DIR	= ./minilibx-linux
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX		= $(MLX_DIR)/libmlx.a


SRCS		= srcs/parsingpone.c srcs/parsingptwo.c srcs/display.c

OBJS		= $(SRCS:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c includes/so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re