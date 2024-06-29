# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 15:27:50 by kfukuhar          #+#    #+#              #
#    Updated: 2024/06/26 15:28:30 by kfukuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
	ar rc $(NAME) $^
	ranlib $(NAME)

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)

re: fclean bonus
