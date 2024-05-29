/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:30 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/23 21:15:36 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	rev_rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_getlastnode(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_list **a)
{
	rev_rotate(a);
}

void	rrb(t_stack_list **b)
{
	rev_rotate(b);
}

void	rrr(t_stack_list **a, t_stack_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
