/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:31:48 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/03 14:51:42 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

// Stack Checking functions 

int ft_checksorted(p_stackliste *stack_a);
int ft_stacklength(p_stackliste *stack_a);



#endif