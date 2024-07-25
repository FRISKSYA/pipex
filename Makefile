# Makefile for pipex project

# Variables
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./src
PRINTF_DIR = ./util/ft_printf
LIBFT_DIR = ./util/libft
GNL_DIR = ./util/get_next_line

# Source files
SRCS_FILES = pipex.c init_pipex.c  ft_cleanup.c ft_exit.c execute_cmd.c 
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
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(GNL)

gdb: $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(GNL) -g

#  --show-leak-kinds=all --track-origins=yes
valgrind: gdb
	valgrind --leak-check=full ./pipex infile "/bin/cat -n" "/bin/wc -l" outfile

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
