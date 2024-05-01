/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:02:15 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/01 16:56:05 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// the split function is using a forbiden fucntion  check it when finish
// also atol
// case to resolve in ft split "   4   2         15" the problem is when we have spaces at the beginnig only

typedef struct p_stackliste{
    int     data;
    int     current_position;
    int     above_mediane;
    int     push_price;
    int     cheapest;
    struct p_stackliste *target_node;
    struct p_stackliste *next;
    struct p_stackliste *prev;
}               p_stackliste;

// Outils Used In Our Main Function Of Push swap

char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
void	ft_putstr(char *s);
void	ft_putstr(char *s);

// Stack Creation Functions

void ft_stack_init(p_stackliste **stack, char **argv, int flag_heapornpot);
void  ft_addnode(p_stackliste **stack_a, int data);
p_stackliste *ft_getlastnode(p_stackliste *stack);

// Stack Checking functions 

int ft_checksorted(p_stackliste *stack_a);
int ft_stacklength(p_stackliste *stack_a);

// Commandes

void ft_swap(p_stackliste **stack);
void sa(p_stackliste **stack);
void sb(p_stackliste **stack);
void ss(p_stackliste **stack_a, p_stackliste **stack_b);
void ft_rotate(p_stackliste **stack);
void ra(p_stackliste **stack);
void rb(p_stackliste **stack);
void rr(p_stackliste **stack_a, p_stackliste **stack_b);
void ft_reverse_rotate(p_stackliste **stack);
void rra(p_stackliste **stack);
void rrb(p_stackliste **stack);
void rrr(p_stackliste **stack_a, p_stackliste **stack_b);
void ft_push_opperation(p_stackliste **destination, p_stackliste **source);
void pa(p_stackliste **stack_a, p_stackliste **stack_b);
void pb(p_stackliste **stack_a, p_stackliste **stack_b);


// Sorting Functions

void ft_sorththree(p_stackliste **stack);
p_stackliste *find_highest(p_stackliste *head);
p_stackliste *find_smallest(p_stackliste *head);
void push_swap(p_stackliste **stack_a, p_stackliste **stack_b);

// Stack Initialization

void  set_current_position(p_stackliste *head);
void  set_mediane_situation(p_stackliste *head);
void  set_push_price(p_stackliste *head, p_stackliste *head_2);
void  set_cheapest_one(p_stackliste *head);
void  set_push_price_from_b(p_stackliste *stack_a, p_stackliste *stack_b);

// Pushing from a to b functions

void push_swap_a(p_stackliste **stack_a, p_stackliste **stack_b);
void ft_target_nodefor_a(p_stackliste *stack_a, p_stackliste *stack_b);
void ft_initnodefor_a(p_stackliste *stack_a, p_stackliste *stack_b);
void set_cheapest_one(p_stackliste *head);
p_stackliste *ft_returncheapest(p_stackliste *head);

// Sorintg Movements

void rotate_both(p_stackliste **stack_a, p_stackliste **stack_b, p_stackliste *cheapest_node);
void reverse_rotate_both(p_stackliste **stack_a, p_stackliste **stack_b, p_stackliste *cheapest_node);
void	finish_rotation(p_stackliste **stack, p_stackliste *top_node, char stack_name);
void rotate_both_b_to_a(p_stackliste **head, p_stackliste **head_2, p_stackliste *cheapest_node);
void reverse_rotate_both_b_to_a(p_stackliste **head, p_stackliste **head_2, p_stackliste *cheapest_node);

// Pushing from b to a funcrions

void  push_swap_b(p_stackliste **stack_a, p_stackliste **stack_b);
void ft_move_nodesfrom_b_to_a(p_stackliste **stack_a, p_stackliste **stack_b);
void ft_target_nodefor_b(p_stackliste *stack_a, p_stackliste *stack_b);
void ft_initnodefor_b(p_stackliste *stack_a, p_stackliste *stack_b);
void set_default(p_stackliste *head);

//Errors handling functions

int ft_checkrepetition(p_stackliste *head, int number);
void ft_freelinkedlist(p_stackliste **head);
void  ft_freeheapargv(char **argv);
void ft_freeerrors(p_stackliste **head, char **argv, int flag_heapornot);
int syntaxe_error(const char *string);
void ft_deppanage(p_stackliste **stack, p_stackliste *top_node);

#endif