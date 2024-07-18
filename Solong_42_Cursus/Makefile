# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 14:23:22 by abait-ou          #+#    #+#              #
#    Updated: 2024/07/18 16:35:54 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
SRCS		= ./so_long.c Outils/Libft/ft_putstr.c Outils/Libft/ft_strdup.c Outils/Libft/ft_strlen.c Outils/Libft/ft_strncmp.c Outils/Libft/ft_putnbr.c\
			  Outils/gnl/get_next_line.c Outils/gnl/get_next_line_utils.c\
			  Outils/Parsing/Part_1.c Outils/Parsing/Part_2.c Outils/Parsing/Part_3.c Outils/Parsing/Part_4.c\
			  Flood_fill/Part_1.c Flood_fill/Part_2.c\
			  Game/Part_01.c Game/Part_02.c Game/Part_03.c\
			  minilibx-linux/libmlx_Linux.a\
			  
			  
				
OBJS		= $(SRCS:.c=.o)
FLAGS		= -Wall -Werror -Wextra
COMPILER	= gcc
MLX_FLAGS   = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11


all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(FLAGS)  $(OBJS)  -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -g3 -o $(NAME)
	@echo "Compilation Done\n" 

%.o:%.c
	@$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(NAME) $(OBJS)
re:
	fclean all


