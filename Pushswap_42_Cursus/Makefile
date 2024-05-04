# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:58:28 by abait-ou          #+#    #+#              #
#    Updated: 2024/05/03 15:07:41 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= push_swap.c Outils/ft_atol.c Stack_init/ft_stack_init.c Outils/ft_split.c Commandes/ft_swap.c\
		Outils/ft_putstr.c Commandes/ft_rotate.c Commandes/ft_reverse_rotate.c Commandes/ft_push_opperation.c\
		Sorting/ft_sorting.c Sorting/ft_pushingfrom_a_to_b.c Stack_init/ft_structinit.c Sorting/ft_move_nodes.c\
		Sorting/ft_pushingfrom_b_to_a.c Stack_init/ft_structinit_2.c Errors_handling/Errors_handling.c
NAME	= push_swap
OBJS	= $(SRCS:.c=.o)
COMPILER = gcc
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(OBJS) -o $(NAME)

%.o: %.c
	$(COMPILER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
