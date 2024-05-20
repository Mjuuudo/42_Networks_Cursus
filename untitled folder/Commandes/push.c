/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:31 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/20 14:11:27 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(stack_list **dst, stack_list **src)
{
	stack_list	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(stack_list **a, stack_list **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(stack_list **b, stack_list **a)
{
	push(b, a);
	ft_putstr("pb\n");
}
