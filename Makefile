# Makefile for pipex project

# Variables
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./srcs
PRINTF_DIR = ./utils/ft_printf
LIBFT_DIR = ./utils/libft
GNL_DIR = ./utils/get_next_line

# Source files
SRCS_FILES = pipex.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL =  $(GNL_DIR)/get_next_line.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(GNL)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

# Dependencies
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
