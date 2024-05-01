/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_opperation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:05:16 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/26 14:15:26 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_push_opperation(p_stackliste **destination, p_stackliste **source)
{
    p_stackliste	*push_node; //Used to store the pointer to the node to be pushed

	if (!*source) //The top node of a stack to be pushed
		return ;
	push_node = *source; //The top node to push is assigned to the `t_stack_node` variable
	*source = (*source)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*source) //Check if the current node exists
		(*source)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*destination) //Check if the other stack is empty
	{
		*destination = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *destination; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*destination = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void pa(p_stackliste **stack_a, p_stackliste **stack_b)
{
    ft_push_opperation(stack_a, stack_b);
    ft_putstr("pa\n");
}

void pb(p_stackliste **stack_a, p_stackliste **stack_b)
{
    ft_push_opperation(stack_b, stack_a);
    ft_putstr("pb\n");
}