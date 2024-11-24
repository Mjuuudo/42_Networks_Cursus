COMPILER = cc
NAME	 = philo
SRCS 	 = philosophers.c Parsing/Part_01.c Outils/Part_01.c Error_Handling/Part_01.c\
			Data_init/Part_01.c Dinner_simu/routine.c Dinner_simu/monitor.c Dinner_simu/Dinner_simu.c\
			Outils/Part_02.c Dinner_simu/routine_actions.c


OBJS     = ${SRCS:.c=.o}
FLAGS    = -Wall -Werror -Wextra #-fsanitize=thread -pthread

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	@$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean:
	@rm -rf $(OBJS) $(NAME)
re: fclean all