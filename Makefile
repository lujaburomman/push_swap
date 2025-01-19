# Path to libft
LIBFT_DIR = ./libft

# Path to ft_printf
FT_PRINTF_DIR = ./ftprintf

# Rules
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c sort_utils.c input_utils.c operations.c main.c

OBJS = $(SRCS:%.c=%.o)

INCLUDES = -I$(LIBFT_DIR)/include -I$(FT_PRINTF_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf
CFLAGS += $(INCLUDES)

# Build the project
all: $(NAME)

$(NAME): $(OBJS) libft ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
libft:
	make -C $(LIBFT_DIR)

# Build ft_printf
ft_printf:
	make -C $(FT_PRINTF_DIR)

# Clean object files
clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re libft ft_printf