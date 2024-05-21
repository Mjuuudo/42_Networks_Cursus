# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 20:25:56 by abait-ou          #+#    #+#              #
#    Updated: 2024/05/21 13:15:05 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN = \033[1;32m
YELLOW = \x1b[33m
RED = \033[1;31m
BLUE = \033[34m
MAGENTA = \033[35m
ORANGE = \033[1;38;5;208m
STOP_COLOR = \033[0m

SRCS 		 = push_swap.c Outils/ft_split.c Outils/ft_atol.c Outils/ft_print.c Stack_Creation/ft_stackcreation.c Error_handling/ft_Errors.c\
				Commandes/push.c Commandes/rev_rotate.c Commandes/rotate.c Commandes/swap.c Sorting/ft_movements.c Sorting/ft_pushing_phase01.c\
				Sorting/ft_pushing_phase02.c Sorting/ft-sortthree.c Sorting/Additional.c\
				

OBJS		 = $(SRCS:.c=.o)
NAME		 = push_swap 
COMPILER     = gcc
REMOVE		 = rm -rf

all:	$(NAME)
	
$(NAME): $(OBJS)
	@$(COMPILER) $(OBJS) -o $(NAME)

%.o: %.c
	@$(COMPILER) -c $< -o $@
	@echo "$(ORANGE)[!] $(YELLOW) Compiling The File $<"
	@echo "$(GREEN)[✔]Done ... ! "
	
 clean:
	@$(REMOVE) $(OBJS)
	@echo "$(RED)[!] $(YELLOW) Removing in progress ..."
	@echo "$(GREEN)[✔]  Done ... ! "
fclean:
	@$(REMOVE) $(NAME) $(OBJS)
	@echo "$(RED)[!] $(YELLOW) Removing in progress ..."
	@echo "$(GREEN)[✔]  Done ... ! "
re:   fclean all
.PHONY:  all clean fclean re