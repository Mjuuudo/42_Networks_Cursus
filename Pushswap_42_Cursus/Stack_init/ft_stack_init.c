/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:21:20 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/01 16:04:20 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_stacklength(p_stackliste *stack_a)
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

int ft_checksorted(p_stackliste *stack_a)
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

p_stackliste *ft_getlastnode(p_stackliste *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
    {
        stack = stack->next;
    }
    return (stack);
}

void  ft_addnode(p_stackliste **stack_a, int data)
{
    p_stackliste *new_node;
    p_stackliste *last_node;
    
    if (!stack_a)
            return ;
    new_node = malloc(sizeof(p_stackliste));
    if (!new_node)
            return ;
    new_node->data = data;
    new_node->next = NULL;
    if (!(*stack_a))
    {
            *stack_a = new_node;
            new_node->prev = NULL;       
    }
    else
    {
        last_node = ft_getlastnode((*stack_a));
        last_node->next = new_node;
        new_node->next  = NULL;
        new_node->prev  = last_node;
    }
}
void ft_stack_init(p_stackliste **stack, char **argv, int flag_heapornpot)
{
    long number;
    int compteur;

    compteur = 0;
    while (argv[compteur])
    {
        if (syntaxe_error(argv[compteur]))
            ft_freeerrors(stack, argv, flag_heapornpot);
        number = ft_atol(argv[compteur++]);
        if (number > INT_MAX || number < INT_MIN)
            ft_freeerrors(stack, argv, flag_heapornpot);
        if (ft_checkrepetition(*stack, (int)number))
            ft_freeerrors(stack, argv, flag_heapornpot);
        ft_addnode(stack, (int)number);
    }
    // printf("stack length : %d\n", ft_stacklength(*stack)); 
    if (flag_heapornpot)
        ft_freeheapargv(argv);
    
}