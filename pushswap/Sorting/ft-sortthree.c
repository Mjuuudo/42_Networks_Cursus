/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-sortthree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:17:33 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/10 15:49:58 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(stack_list **a) 
{
	stack_list	*biggest_node; 

	biggest_node = find_max(*a);
	if (biggest_node == *a) 
		ra(a); 
	else if ((*a)->next == biggest_node) 
		rra(a); 
	if ((*a)->data > (*a)->next->data) 
		sa(a);
}

stack_list	*find_min(stack_list *stack)
{
	long			min; 
	stack_list	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX; 
	while (stack) 
	{
		if (stack->data < min) 
		{
			min = stack->data; 
			min_node = stack; 
		}
		stack = stack->next; 
	}
	return (min_node); 
}

stack_list	*find_max(stack_list *stack)
{
	long			max; 
	stack_list	*max_node; 

	if (!stack)
		return (NULL);
	max = LONG_MIN; 
	while (stack) 
	{
		if (stack->data > max) 
		{
			max = stack->data;
			max_node = stack; 
		}
		stack = stack->next; 
	}
	return (max_node);
}