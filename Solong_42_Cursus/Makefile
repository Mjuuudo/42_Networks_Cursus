# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 14:23:22 by abait-ou          #+#    #+#              #
#    Updated: 2024/06/10 15:27:11 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
SRSC		= so_long.c Outils/Parsing/Part_1.c Outils/Libft/ft_strlen.c Outils/Libft/ft_strncmp.c Outils/Libft/ft_putstr.c\
				Outils/gnl/get_next_line.c Outils/gnl/get_next_line_utils.c\
				
OBJS		= ${SRSC:.c = .o}
FLAGS		= -Wall -Werror -Wextra
COMPILER	= gcc
MLX_FLAGS   = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11


all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS)  $(OBJS)  -o $(NAME)

%.o:%.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(NAME) $(OBJS)
re:
	fclean all
	
	