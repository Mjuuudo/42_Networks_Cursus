/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushingfrom_a_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:33:02 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/01 14:50:41 by abait-ou         ###   ########.fr       */
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
    p_stackliste	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	p_stackliste	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (stack_a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = stack_b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->data < stack_a->data 
				&& current_b->data > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->data; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			stack_a->target_node = find_highest(stack_b); //If so, find the biggest `nbr` and set this as the target node
		else
			stack_a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		stack_a = stack_a->next; //Move to the next `a` node to find it's target `b` node
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
    finish_rotation(stack_b, cheapest->target_node, 'b');
    finish_rotation(stack_a, cheapest, 'a');
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