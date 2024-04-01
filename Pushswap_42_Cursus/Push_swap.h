#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

typedef struct pushswap_list{
    int data;
    int current_position;
    struct pushswap_list *prev;
    struct pushswap_list *next;
} pushswap_list;

//Outils That Help us handling cases and opperations

char	**ft_split(char const *s, char c);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
long	ft_atoi(const char *str);

// There is the prototypes of the function which controles the linkled lists (stacks)

pushswap_list *get_last_node(pushswap_list *head);
void append_node(pushswap_list **head, int data);
size_t linked_list_len(pushswap_list *head);

#endif