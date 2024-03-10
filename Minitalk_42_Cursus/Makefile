FLAGS = -Werror -Wextra -Wall
OUTILS = ./Outils/ft_atoi.c ./Outils/ft_isdigit.c ./Outils/ft_putchar_fd.c ./Outils/ft_putnbr_fd.c ./Outils/ft_putstr_fd.c
NAME_SERVER=server
NAME_CLIENT=client

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT): ./ft_client/client.c $(OUTILS)
	cc $(FLAGS) ./ft_client/client.c $(OUTILS) -o $(NAME_CLIENT)
$(NAME_SERVER): ./ft_server/server.c $(OUTILS)
	cc $(FLAGS) ./ft_server/server.c $(OUTILS) -o $(NAME_SERVER)

fclean:
	rm -f client server 
	rm -f client_bonus server_bonus

clean:

re: fclean all

bonus: client_bonus server_bonus

client_bonus: ./ft_client/client_bonus.c $(OUTILS)
	cc $(FLAGS) ./ft_client/client_bonus.c $(OUTILS) -o client_bonus
server_bonus: ./ft_server/server_bonus.c $(OUTILS)
	cc $(FLAGS) ./ft_server/server_bonus.c $(OUTILS) -o server_bonus

.PHONY: all fclean clean re bonus