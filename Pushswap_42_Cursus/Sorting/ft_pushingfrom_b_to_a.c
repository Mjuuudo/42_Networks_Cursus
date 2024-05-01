/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushingfrom_b_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:28:50 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/01 14:07:06 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_initnodefor_b(p_stackliste *stack_a, p_stackliste *stack_b)
{
    set_current_position(stack_a);
    set_current_position(stack_b);
    set_mediane_situation(stack_a);
    set_mediane_situation(stack_b);
    ft_target_nodefor_b(stack_a, stack_b);
    set_push_price(stack_b, stack_a);
    set_cheapest_one(stack_b);
}

void ft_target_nodefor_b(p_stackliste *stack_a, p_stackliste *stack_b)
{
    p_stackliste	*current_a; 
	p_stackliste	*target_node; 
	long			best_match_index; 

	while (stack_b)
	{
		best_match_index = LONG_MAX; 
		current_a = stack_a; 
		while (current_a) 
		{
			if (current_a->data > stack_b->data 
				&& current_a->data < best_match_index) 
			{
				best_match_index = current_a->data; 
				target_node = current_a; 
			}
			current_a = current_a->next; 
		}
		if (best_match_index == LONG_MAX) 
			stack_b->target_node = find_smallest(stack_a);
		else
			stack_b->target_node = target_node; 
		stack_b = stack_b->next; 
	}
   
}

void ft_deppanage(p_stackliste **stack, p_stackliste *top_node)
{
    while (top_node->current_position != 0)
    {
        if (top_node->above_mediane)
				ra(stack);
			else
				rra(stack);
        set_current_position(*stack);
    }
}

void ft_move_nodesfrom_b_to_a(p_stackliste **stack_a, p_stackliste **stack_b)
{
    p_stackliste *cheapest;
    cheapest = ft_returncheapest(*stack_b);
    
    if (cheapest->above_mediane && cheapest->target_node->above_mediane)
        rotate_both(stack_b, stack_a, cheapest);
    else if (!(cheapest->above_mediane && cheapest->target_node->above_mediane))
        reverse_rotate_both(stack_b, stack_a, cheapest);
    finish_rotation(stack_b, cheapest, 'b');
    finish_rotation(stack_a, cheapest->target_node, 'a');
    // ft_deppanage(stack_a, cheapest->target_node);
    pa(stack_a, stack_b);
}



void  push_swap_b(p_stackliste **stack_a, p_stackliste **stack_b)
{
    int stack_length;
    p_stackliste *smallest_one;

    stack_length = ft_stacklength((*stack_b));
    while (stack_length > 0)
    {
     ft_initnodefor_b(*stack_a, *stack_b);
     ft_move_nodesfrom_b_to_a(stack_a, stack_b);
     stack_length--;   
    }
    smallest_one = find_smallest(*stack_a);
    if (smallest_one->above_mediane)
        while((*stack_a) != smallest_one)
                ra(stack_a);
    if (!smallest_one->above_mediane)
        while ((*stack_a) != smallest_one)
                rra(stack_a); 
}











