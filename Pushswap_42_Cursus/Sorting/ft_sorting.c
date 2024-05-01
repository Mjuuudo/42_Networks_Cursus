/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:13:05 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/26 21:25:53 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

p_stackliste *find_highest(p_stackliste *head)
{
    p_stackliste *highest_one;
    int          high_value;

    if (head == NULL)
        return (NULL);
    high_value = INT_MIN;
    while (head)
    {
        if (head->data > high_value)
        {
            high_value = head->data;
            highest_one = head;
        }
        head = head->next;
    }    
    return (highest_one);
}

p_stackliste *find_smallest(p_stackliste *head)
{
    p_stackliste *smallest_one;
    long          smallest_value;

    smallest_value = LONG_MAX;
    while (head)
    {
        if (smallest_value > head->data)
        {
            smallest_one = head;
            smallest_value = head->data;
        }
        head = head->next;
    }
    return (smallest_one);
    
}

void ft_sorththree(p_stackliste **stack)
{
    if ((*stack) == find_highest(*stack))
        ra(stack);
    else if ((*stack)->next == find_highest(*stack))
        rra(stack);
    if ((*stack)->data > (*stack)->next->data)
        sa(stack);
}

void push_swap(p_stackliste **stack_a, p_stackliste **stack_b)
{
    push_swap_a(stack_a, stack_b);
    set_current_position(*stack_a);
    set_current_position(*stack_b);
    set_mediane_situation(*stack_a);
    set_mediane_situation(*stack_b);
    set_default(*stack_b);
    push_swap_b(stack_a, stack_b);
}

