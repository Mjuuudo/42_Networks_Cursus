/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushing_phase01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:21:51 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/21 12:02:27 by abait-ou         ###   ########.fr       */
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
		if (i < median)
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
	int			size_a;
	int			size_b;
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
