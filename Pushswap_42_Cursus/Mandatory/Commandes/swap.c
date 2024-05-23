/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:25 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/21 13:05:48 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack_list **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_list **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_stack_list **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack_list **a, t_stack_list **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
