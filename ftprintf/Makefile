#Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = \
    $(SRC_DIR)/ft_printf.c \
    $(SRC_DIR)/ft_putchar.c \
    $(SRC_DIR)/ft_putstr.c \
    $(SRC_DIR)/ft_putnbr.c \
    $(SRC_DIR)/ft_puthex.c \
    $(SRC_DIR)/ft_putptr.c \
    $(SRC_DIR)/ft_putunsigned.c

OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#Rules
all : $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Archiving object files into $(NAME)..."
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(NAME) created successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Checking if $< exists..."
	@test -f $< || (echo "Error: $< does not exist!" && exit 1)
	@echo "Creating directory: $(dir $@)"
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned!"

fclean : clean
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) cleaned!"

re : fclean all

.PHONY : all clean fclean re
