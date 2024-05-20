/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:30 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/20 14:11:36 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(stack_list **stack)
{
	stack_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_getlastnode(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(stack_list **a)
{
	rev_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(stack_list **b)
{
	rev_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(stack_list **a, stack_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr("rrr\n");
}
