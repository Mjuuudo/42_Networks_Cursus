# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 13:37:52 by abait-ou          #+#    #+#              #
#    Updated: 2024/01/18 13:37:54 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_putstr.c\
				ft_printf_hexa.c ft_printf_Uhexa.c  ft_putnbr.c\
				ft_printf_pointer.c ft_printf_unsigned.c
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@echo "creating $@"
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	@echo "compiling $< to $@"
	@$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	@echo "clean"
	@rm -f $(OBJS)

fclean: clean
	@echo "fclean"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

