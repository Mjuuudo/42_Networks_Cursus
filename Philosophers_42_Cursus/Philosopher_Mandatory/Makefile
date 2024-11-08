COMPILER = cc
NAME	 = philosopher
SRCS 	 = philosophers.c Parsing/Part_01.c Outils/Part_01.c Error_Handling/Part_01.c\
			Data_init/Part_01.c Dinner_simu/routine.c Dinner_simu/monitor.c


OBJS     = ${SRCS:.c=.o}
FLAGS    = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	@$(COMPILER) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean:
	@rm -rf $(OBJS) $(NAME)