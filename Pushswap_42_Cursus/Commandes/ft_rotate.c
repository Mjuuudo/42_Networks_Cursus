/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:54:04 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/26 10:12:38 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_rotate(p_stackliste **stack)
{
    p_stackliste *target;
    p_stackliste *last_node;

    if (*stack == NULL)
        return ;
    target = (*stack);
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node = ft_getlastnode(*stack);
    target->prev = last_node;
    last_node->next = target;
    target->next = NULL;
}
void ra(p_stackliste **stack)
{
    ft_rotate(stack);
    ft_putstr("ra\n");
}
void rb(p_stackliste **stack)
{
    ft_rotate(stack);
    ft_putstr("rb\n");
}
void rr(p_stackliste **stack_a, p_stackliste **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr("rr\n");
}
