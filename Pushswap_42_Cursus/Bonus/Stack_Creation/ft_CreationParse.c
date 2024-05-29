/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_CreationParse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:13:43 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/29 15:56:54 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_stacklength(t_stack_list *stack_a)
{
	int	compteur;

	compteur = 0;
	while (stack_a)
	{
		compteur++;
		stack_a = stack_a->next;
	}
	return (compteur);
}

int	ft_checksorted(t_stack_list *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

t_stack_list	*ft_getlastnode(t_stack_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_addnode(t_stack_list **stack, int data)
{
	t_stack_list	*node;
	t_stack_list	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_list));
	if (!node)
		return ;
	node->next = NULL;
	node->data = data;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_getlastnode(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_stack_init(t_stack_list **a, char **argv, int flag_heapornot)
{
	long long	n;
	int			i;

	if (flag_heapornot == 1)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (ft_checkargtype(argv[i]) == 0)
		{
			if (ft_check_space(argv[i]) == 1)
				ft_freeerrors(a, argv, flag_heapornot);
			ft_creationofstack(a, argv[i], flag_heapornot, argv);
		}
		else if (ft_checkargtype(argv[i]) == 1)
		{
			ft_hardcreation(a, argv[i], 1);
		}
		else
			ft_freeerrors(a, argv, 0);
		i++;
	}
}
