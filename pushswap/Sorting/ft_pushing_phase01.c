/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushing_phase01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:21:51 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/18 18:28:07 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(stack_list *stack)
{
	int	i; 
	int	median; 

	i = 0; 
	if (!stack) 
		return ;
	median = ft_stacklength(stack) / 2; 
	while (stack) 
	{
		stack->current_position = i; 
		if (i <= median) 
			stack->above_mediane = 1;
		else
			stack->above_mediane = 0;
		stack = stack->next; 
		++i; 
	}
}

void	ft_set_target_a(stack_list *a, stack_list *b)
{
	stack_list	*current_b;
	stack_list	*target_node; 
	long			best_match_index; 

	while (a) 
	{
		best_match_index = LONG_MIN; 
		current_b = b;
		while (current_b) 
		{
			if (current_b->data < a->data 
				&& current_b->data > best_match_index) 
			{
				best_match_index = current_b->data; 
				target_node = current_b; 
			}
			current_b = current_b->next; 
		}
		if (best_match_index == LONG_MIN) 
			a->target_node = find_max(b);
		else
			a->target_node = target_node; 
		a = a->next;
	}
}

void	ft_push_price(stack_list **a, stack_list **b) 
{
	int		size_a;
	int		size_b;
	stack_list	*temp;

	size_a = ft_stacklength(*a);
	size_b = ft_stacklength(*b);
	temp = *a;
	while (temp)
	{
		if (temp->above_mediane == 0)
			temp->push_cost = size_a - (temp->current_position);
		else
			temp->push_cost = temp->current_position;
		if (temp->target_node->above_mediane == 1)
			temp->push_cost += temp->target_node->current_position;
		else
			temp->push_cost += size_b - (temp->target_node->current_position);
		ft_calc_movtg(a, b, temp);
		temp = temp->next;
	}
	
}

void	ft_calc_movtg(stack_list **stack_a, stack_list **stack_b, stack_list *node)
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
		if (ft_stacklength(*stack_a) - node->current_position 
			< ft_stacklength(*stack_b) - node->target_node->current_position)
			node->push_cost -= ft_stacklength(*stack_a) - node->current_position;
		else
			node->push_cost -= ft_stacklength(*stack_b) - node->target_node->current_position;
	}
}

void	ft_set_cheapest(stack_list *stack) 
{
	long			cheapest_value;
	stack_list		*cheapest_node; 

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
	int		min_qtmoves;

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


void	init_nodes_a(stack_list *a, stack_list *b)
{
	current_index(a);
	current_index(b);
	ft_set_target_a(a, b);
	ft_push_price(&a, &b);
	ft_set_cheapest(a);

	// stack_list *current_a;

	// current_a = a;
	// while (current_a)
	// {
	// 	printf("data %d target %d push cost %d taget index %d\n", current_a->data ,current_a->target_node->data, current_a->push_cost, current_a->target_node->current_position);
	// 	current_a = current_a->next;
	// }
}