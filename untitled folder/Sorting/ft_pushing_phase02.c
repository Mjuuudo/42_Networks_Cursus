/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushing_phase02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:35:41 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/21 13:07:47 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_for_push(t_stack_list **stack, t_stack_list *top_node, char stack_name)
{
	while (*stack != top_node)
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
	}
}

t_stack_list	*ft_get_cheapest(t_stack_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	set_target_b(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*current_a;
	t_stack_list	*target_node;
	long		best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	max_on_top(t_stack_list **b)
{
	t_stack_list	*max;

	max = find_max(*b);
	while ((*b)->data != max->data)
	{
		if (max->above_mediane)
			rb(b);
		else
			rrb(b);
	}
}

void	init_nodes_b(t_stack_list *a, t_stack_list *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
