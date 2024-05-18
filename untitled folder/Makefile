# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 20:25:56 by abait-ou          #+#    #+#              #
#    Updated: 2024/05/10 15:49:37 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		 = push_swap.c Outils/ft_split.c Outils/ft_atol.c Outils/ft_print.c Stack_Creation/ft_stackcreation.c Error_handling/ft_Errors.c\
				Commandes/push.c Commandes/rev_rotate.c Commandes/rotate.c Commandes/swap.c Sorting/ft_movements.c Sorting/ft_pushing_phase01.c\
				Sorting/ft_pushing_phase02.c Sorting/ft-sortthree.c\
				

OBJS		 = $(SRCS:.c=.o)
NAME		 = push_swap 
COMPILER     = gcc
REMOVE		 = rm -rf

all:	$(NAME)
	
$(NAME): $(OBJS)
	$(COMPILER) $(OBJS) -o $(NAME)

%.o: %.c
	$(COMPILER) -c $< -o $@
 clean:
	$(REMOVE) $(OBJS)
fclean:
	$(REMOVE) $(NAME)
re:   fclean all
.PHONY:  all clean fclean re