/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:23:39 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/25 14:52:41 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap(p_stackliste **stack)
{
    p_stackliste *current;
    p_stackliste *next;
    p_stackliste *temp;
    p_stackliste *last;
    
    if (ft_stacklength(*stack) == 1 || stack == NULL)
        return ;
    current = *stack;
    next = current->next;
    last = next->next;
    temp = current;
    *stack = next;
    next->next = temp;
    next->prev = NULL;
    current->next = last;
    current->prev = next;
}

void sa(p_stackliste **stack)
{
    ft_swap(stack);
    ft_putstr("sa\n");
}
void sb(p_stackliste **stack)
{
    ft_swap(stack);
    ft_putstr("sb\n");
}

void ss(p_stackliste **stack_a, p_stackliste **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    ft_putstr("ss\n");
}