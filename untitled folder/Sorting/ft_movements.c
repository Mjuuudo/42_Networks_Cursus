/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:30:47 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/21 10:26:10 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(stack_list **a, stack_list **b,
		stack_list *cheapest_node)
{
	while (cheapest_node->target_node->current_position != 0
		&& cheapest_node->current_position != 0)
	{
		rr(a, b);
		current_index(*a);
		current_index(*b);
	}
}

static void	rev_rotate_both(stack_list **a, stack_list **b,
		stack_list *cheapest_node)
{
	while (cheapest_node->target_node->current_position != 0
		&& cheapest_node->current_position != 0)
	{
		rrr(a, b);
		current_index(*a);
		current_index(*b);
	}
}

static void	move_a_to_b(stack_list **a, stack_list **b)
{
	stack_list	*cheapest_node;

	cheapest_node = ft_calc_lessmoves(a);
	if (cheapest_node->above_mediane == 1
		&& cheapest_node->target_node->above_mediane == 1)
		rotate_both(a, b, cheapest_node);
	else if ((cheapest_node->above_mediane == 0)
		&& (cheapest_node->target_node->above_mediane == 0))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	move_b_to_a(stack_list **a, stack_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	ft_push_swap(stack_list **a, stack_list **b)
{
	int	len_a;

	len_a = ft_stacklength(*a);
	if (len_a-- > 3 && !ft_checksorted(*a))
		;
	pb(a, b);
	if (len_a-- > 3 && !ft_checksorted(*a))
		pb(b, a);
	while (len_a-- > 3 && (!ft_checksorted(*a)))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	// max_on_top(b);
	// ft_sort_three(a);
	// while (*b)
	// {
	// 	current_index(*a);
	// 	current_index(*b);
	// 	init_nodes_b(*a, *b);
	// 	move_b_to_a(a, b);
	// }
	// current_index(*a);
	// min_on_top(a);
}
