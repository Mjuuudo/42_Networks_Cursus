/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:25:02 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/01 14:05:57 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_both(p_stackliste **stack_a, p_stackliste **stack_b, p_stackliste *cheapest_node)
{
    // while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
    //         rr(stack_a,  stack_b);
    // set_current_position(*stack_a);
    // set_current_position(*stack_b);
	while (cheapest_node->target_node->current_position > 0
											&& cheapest_node->current_position > 0)
	{	
		rr(stack_a, stack_b);
		set_current_position(*stack_a);
		set_current_position(*stack_b);
	}
}

void reverse_rotate_both(p_stackliste **stack_a, p_stackliste **stack_b, p_stackliste *cheapest_node)
{
    // while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
    //         rrr(stack_a,  stack_b);
    // set_current_position(*stack_a);
    // set_current_position(*stack_b);

	while (cheapest_node->target_node->current_position > 0
											&& cheapest_node->current_position > 0)
	{	
		rrr(stack_a, stack_b);
		set_current_position(*stack_a);
		set_current_position(*stack_b);
	}
}

void	finish_rotation(p_stackliste **stack, p_stackliste *top_node, char stack_name) 
{
	while (top_node->current_position > 0)
	{
		if (stack_name == 'a') 
		{
			if (top_node->above_mediane)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b') 
		{
			if (top_node->above_mediane)
				rb(stack);
			else
				rrb(stack);
		}	
		set_current_position(*stack);
	}
}

void rotate_both_b_to_a(p_stackliste **head, p_stackliste **head_2, p_stackliste *cheapest_node)
{
    while (*head_2 != cheapest_node->target_node && *head != cheapest_node)
            rr(head_2,  head);
    set_current_position(*head);
    set_current_position(*head_2);
}

void reverse_rotate_both_b_to_a(p_stackliste **head, p_stackliste **head_2, p_stackliste *cheapest_node)
{
    while (*head_2 != cheapest_node->target_node && *head != cheapest_node)
            rrr(head_2,  head);
    set_current_position(*head);
    set_current_position(*head_2);
}