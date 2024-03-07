# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:13:02 by abait-ou          #+#    #+#              #
#    Updated: 2023/12/08 13:38:37 by abait-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Werror -Wextra -Wall
NAME		=	libft.a
Compiler	=	cc
CFiles		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
				ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
				ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
CBonus		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
Object		=	$(CFiles:.c=.o)

BObject		=	$(CBonus:.c=.o)

all:	$(NAME) 

$(NAME):	$(Object)

%.o:%.c
	$(Compiler)    $(CFLAGS)    -c    $< -o $@
	ar -rcs $(NAME) $@

bonus: $(BObject)

fclean:		clean
	rm    -f    $(NAME)

clean:
	rm    -f    $(Object)
	rm    -f    $(BObject)

re:	fclean	all

.PHONY:    clean    re    fclean    all    bonus 
