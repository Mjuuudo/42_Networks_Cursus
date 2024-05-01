/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:40 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/25 15:04:27 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_reverse_rotate(p_stackliste **stack)
{
    p_stackliste *target;
    p_stackliste *last_node;

    if (*stack == NULL)
        return ;
    last_node = ft_getlastnode(*stack);
    last_node->prev->next = NULL;
    last_node->next = (*stack);
    last_node->prev = NULL;
    (*stack) = last_node;
    last_node->next->prev = last_node;
}
void rra(p_stackliste **stack)
{
    ft_reverse_rotate(stack);
    ft_putstr("rra\n");
}
void rrb(p_stackliste **stack)
{
    ft_reverse_rotate(stack);
    ft_putstr("rrb\n");
}
void rrr(p_stackliste **stack_a, p_stackliste **stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    ft_putstr("rrr\n");
}