#path to libft
LIBFT_DIR = ../push_swap/libft
LIBFT_INCLUDES = $(LIBFT_DIR)/includes
LIBFT = $(LIBFT_DIR)/libftprintf.a

#path to ft_printf
FTPRINTF_DIR = ../push_swap/ftprintf
FTPRINTF_INCLUDES = $(FTPRINTF_DIR)/includes
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

#rules
NAME = push_swap
SRCS = push_swap.c input_utils.c operations.c main.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_INCLUDES) -I$(FTPRINTF_INCLUDES) -I.

# Build the project
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(NAME)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build ft_printf
$(FTPRINTF):
	make -C $(FTPRINTF_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re