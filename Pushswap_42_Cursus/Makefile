# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 20:03:25 by abait-ou          #+#    #+#              #
#    Updated: 2024/04/20 18:10:27 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS		= -Wall -Werror -Wextra
COMPILER 	= CC
NAME		= push_swap

SRCS 		=  ./Error_handling/errors_handling.c  ./Outils/ft_atol.c  ./Outils/ft_putnbr.c 
				./Outils/ft_putstr	./Outils/ft_split.c ./Sorting/Check_Sort.c ./Sorting/pa.c 
				./Sorting/sa.c ./sorting/sorting_2.c ./sorting/push_swap.c ./sorting/rotation.c 
				./sorting/reverse_rotation.c ./sorting/sorting.c 
				./Stack_Opp/stack_opp.c ./Stack_Opp/stack_init.c ./Stack_Outils/linked_list_outils.c 
OBJS		= $(SRCS:.c=.o)
LIB			= push_swap.a
MAKELIB 	=  ar -rcs
all:		$(NAME)
	
$(NAME) : $(LIB)
		$(COMPILER) $< -o $@

$(LIB)  :  $(OBJS)
		$(MAKELIB) $(LIB) $^
%c.%o   :
		$(COMPILER) $(FLAGS) -c $< -o $@

clean 	:
		rm $(OBJS) $(LIB)
re		:
		clean all
.PHONY	: all clean   re