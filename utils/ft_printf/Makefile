NAME	=	libftprintf.a
SRCS	=	ft_printf.c ft_render.c ft_render_char.c ft_render_str.c ft_render_nbr.c ft_render_nbr_u.c ft_render_nbr_lower_x.c ft_render_nbr_upper_x.c ft_render_address.c
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

re: fclean all
