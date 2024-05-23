# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 20:25:56 by abait-ou          #+#    #+#              #
#    Updated: 2024/05/23 10:07:10 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN = \033[1;32m
YELLOW = \x1b[33m
RED = \033[1;31m
ORANGE = \033[1;38;5;208m

SRCS 		 = push_swap.c Outils/ft_split.c Outils/ft_atol.c Outils/ft_print.c Stack_Creation/ft_stackcreation.c Error_handling/ft_Errors.c\
				Commandes/push.c Commandes/rev_rotate.c Commandes/rotate.c Commandes/swap.c Sorting/ft_movements.c Sorting/ft_pushing_phase01.c\
				Sorting/ft_pushing_phase02.c Sorting/ft-sortthree.c Sorting/Additional.c Stack_Creation/ft_ParsingSuite.c\
				

BONUS_SRCS	 = ../Bonus/checker.c ../Bonus/checker_utils.c ../Bonus/get_next_line_bonus.c ../Bonus/get_next_line_utils.c\
				Outils/ft_split.c Outils/ft_atol.c Outils/ft_print.c Stack_Creation/ft_stackcreation.c Error_handling/ft_Errors.c Stack_Creation/ft_ParsingSuite.c\
				../Bonus/Commandes/push.c ../Bonus/Commandes/rev_rotate.c ../Bonus/Commandes/rotate.c ../Bonus/Commandes/swap.c \
					
BONUS_OBJS	 = $(BONUS_SRCS:.c=.o)
OBJS		 = $(SRCS:.c=.o)
NAME		 = push_swap 
BONUS		 = checker
COMPILER     = gcc
REMOVE		 = rm -rf

all:	$(NAME) 
	
$(NAME): $(OBJS)
	@$(COMPILER) $(OBJS) -o $(NAME)

$(BONUS): $(BONUS_OBJS) 
	@$(COMPILER) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c
	@$(COMPILER) -c $< -o $@
	@echo "@$(ORANGE)[!] @$(YELLOW) Compiling The File $<"
	@echo "$(GREEN)[✔]Done ... ! "
	
 clean:
	@$(REMOVE) $(NAME) $(BONUS) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)[!] $(YELLOW) Removing in progress ..."
	@echo "$(GREEN)[✔]  Done ... ! "
fclean:
	@$(REMOVE) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)[!] $(YELLOW) Removing in progress $(RED).$(GREEN).$(YELLOW). - > $(RED) $(OBJS)"
	@echo "$(GREEN)[✔]  Done ... ! "
re:   fclean all
.PHONY:  all clean fclean re