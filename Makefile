# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ahossein <ahossein@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/10/26 12:38:56 by ahossein      #+#    #+#                  #
#    Updated: 2026/10/30 19:05:45 by ahossein      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_printf.c wnc.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re