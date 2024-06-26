/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcreation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:36:40 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/10 14:33:30 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_stacklength(stack_list *stack_a)
{
    int compteur;

    compteur = 0;
    while(stack_a)
    {
        compteur++;
        stack_a  = stack_a->next;
    }
    return (compteur);
}

int ft_checksorted(stack_list *stack_a)
{
    if (!stack_a)
        return (1);
    while(stack_a->next)
    {
        if (stack_a->data > stack_a->next->data)
            return (0);
        stack_a = stack_a->next;
    }
    return (1);
}

stack_list *ft_getlastnode(stack_list *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
    {
        stack = stack->next;
    }
    return (stack);
}

void	ft_addnode(stack_list **stack, int data) 
{
	stack_list	*node; 
	stack_list	*last_node; 

	if (!stack)
		return ;
	node = malloc(sizeof(stack_list)); 
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

void	ft_stack_init(stack_list **a, char **argv, int flag_heapornot) 
{
	long long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntaxe_error(argv[i]))
			ft_freeerrors(a, argv, flag_heapornot);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) 
			ft_freeerrors(a, argv, flag_heapornot);
		if (ft_checkrepetition(*a, (int)n))
			ft_freeerrors(a, argv, flag_heapornot); 
		ft_addnode(a, (int)n); 
		i++;
	}
    // if (flag_heapornot)
    //     ft_freeheapargv(argv);
}