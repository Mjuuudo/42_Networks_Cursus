/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:41:50 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/12 18:29:00 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


// Linked List (The stack) Nodes Representation

typedef struct linked_list{
    int     data;
    int     current_position;
    int     push_price;
    int     above_mediane;
    int     cheapest;
    struct linked_list *target_node;
    struct linked_list *prev;
    struct linked_list *next;
}               linked_list;

// Outils Used To Manupilate The Stacks And Translate Data

long	ft_atol(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);

// Linked list Handler Functions

void ft_addnode(linked_list **head, int data);
linked_list *ft_lastnode(linked_list *head);
int ft_linkedlength(linked_list *head);

// Error Handling Functions

void ft_freeerrors(linked_list **head, char **argv, int flag_heapornot);
int syntaxe_error(const char *string);
void  ft_freeheapargv(char **argv);
void ft_freelinkedlist(linked_list **head);
int ft_checkrepetition(linked_list *head, int number);

// Manipulation  Fucntion

void sa(linked_list **head);
void sb(linked_list **head);
void ss(linked_list **head);
void ft_push_opperation(linked_list **destination, linked_list **source);
void pa(linked_list **head, linked_list **head_target);
void pb(linked_list **head, linked_list **head_target);
void ft_rotation_stack(linked_list **head);
void ra(linked_list **head);
void rb(linked_list **head);
void  ft_reverse_rotation_stack(linked_list **head);
void rra(linked_list *head);
void rrb(linked_list *head);
void rrr(linked_list **head, linked_list **head_2);


//  Sorting Function

int  ft_issorted(linked_list **head);

// Initialisation Function

#endif