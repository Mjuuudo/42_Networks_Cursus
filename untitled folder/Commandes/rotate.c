/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:28 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/20 14:11:39 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(stack_list **stack)
{
	stack_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_getlastnode(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(stack_list **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(stack_list **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(stack_list **a, stack_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
