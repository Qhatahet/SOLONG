CC = cc

CFLAGS = -Werror -Wextra -Wall

MLXFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = so_long.c error_check.c map.c valid_path.c exit_game_handlers.c player_movement.c draw_map.c init_game.c\

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS)  $(OBJS) $(MLXFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
re: fclean all

.PHONY:fclean all clean re
