/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:21:49 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/20 14:25:55 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_calc_movtg(stack_list **stack_a, stack_list **stack_b,
		stack_list *node)
{
	if (node->above_mediane == 1 && node->target_node->above_mediane == 1)
	{
		if (node->current_position < node->target_node->current_position)
			node->push_cost -= node->current_position;
		else
			node->push_cost -= node->target_node->current_position;
	}
	else if (node->above_mediane == 0 && node->target_node->above_mediane == 0)
	{
		if (ft_stacklength(*stack_a)
			- node->current_position < ft_stacklength(*stack_b)
			- node->target_node->current_position)
			node->push_cost -= ft_stacklength(*stack_a)
				- node->current_position;
		else
			node->push_cost -= ft_stacklength(*stack_b)
				- node->target_node->current_position;
	}
}

void	ft_set_cheapest(stack_list *stack)
{
	long		cheapest_value;
	stack_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

stack_list	*ft_calc_lessmoves(stack_list **stack_a)
{
	stack_list	*temp_a;
	stack_list	*selected_node;
	int			min_qtmoves;

	temp_a = *stack_a;
	selected_node = NULL;
	min_qtmoves = INT_MAX;
	while (temp_a != NULL)
	{
		if (temp_a->push_cost < min_qtmoves)
		{
			min_qtmoves = temp_a->push_cost;
			selected_node = temp_a;
		}
		temp_a = temp_a->next;
	}
	return (selected_node);
}

void	min_on_top(stack_list **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_mediane)
			ra(a);
		else
			rra(a);
	}
}
