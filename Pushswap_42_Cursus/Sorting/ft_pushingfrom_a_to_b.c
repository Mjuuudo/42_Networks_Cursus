/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushingfrom_a_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:33:02 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/26 20:09:14 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_initnodefor_a(p_stackliste *stack_a, p_stackliste *stack_b)
{
    set_current_position(stack_a);
    set_current_position(stack_b);
    set_mediane_situation(stack_a);
    set_mediane_situation(stack_b);
    ft_target_nodefor_a(stack_a, stack_b);
    set_push_price(stack_a, stack_b);
    set_cheapest_one(stack_a);
}
void ft_target_nodefor_a(p_stackliste *stack_a, p_stackliste *stack_b)
{
    p_stackliste *current_b;
    p_stackliste *target_node;
    long           difference;

    while (stack_a)
    {
        difference = LONG_MIN;
        current_b = stack_b;
        while (current_b)
        {
            if (stack_a->data > current_b->data 
                                                && current_b->data > difference)
                {
                    target_node = current_b;
                    difference = current_b->data;
                }
                current_b = current_b->next;
        }
        if (difference == LONG_MIN)
            stack_a->target_node = find_highest(stack_b);
        else
            stack_a->target_node = target_node; 
        stack_a = stack_a->next; 
    }
    
}
p_stackliste *ft_returncheapest(p_stackliste *head)
{
    p_stackliste *cheapest;

    while (head)
    {
        if (head->cheapest == 1)
        {
            cheapest = head;
        }
        head = head -> next; 
    }
    return (cheapest);
}
void ft_move_nodesfrom_a_to_b(p_stackliste **stack_a, p_stackliste **stack_b)
{
    p_stackliste *cheapest;

    cheapest = ft_returncheapest(*stack_a);
    if (cheapest->above_mediane && cheapest->target_node->above_mediane)
        rotate_both(stack_a, stack_b, cheapest);
    else if (!(cheapest->above_mediane && cheapest->target_node->above_mediane))
        reverse_rotate_both(stack_a, stack_b, cheapest);
    finish_rotation(stack_b, cheapest->target_node, 'a');
    finish_rotation(stack_a, cheapest, 'b');
    pb(stack_a, stack_b);
}

void push_swap_a(p_stackliste **stack_a, p_stackliste **stack_b)
{
    int stack_length;
    p_stackliste *b;
    b = *stack_b;
    
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    
    stack_length = ft_stacklength((*stack_a));
    while( stack_length > 3)
    {
        ft_initnodefor_a(*stack_a, *stack_b);
        ft_move_nodesfrom_a_to_b(stack_a, stack_b);
        stack_length--;
    }
    ft_sorththree(stack_a);
}