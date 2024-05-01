/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:30:18 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/26 18:51:44 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void  set_current_position(p_stackliste *head)
{
    int compteur;

    compteur = 0;
    if (head == NULL)
        return ;
    while (head)
    {
        head->current_position = compteur++;
        head = head->next;
    }
}

void  set_mediane_situation(p_stackliste *head)
{
    int stack_length;
    int compteur;

    compteur = 0;
    stack_length = ft_stacklength(head);
    while (head)
    {
        if (compteur <= (stack_length / 2))
            head->above_mediane = 1;
        else
            head->above_mediane = 0;
        compteur++;
        head = head->next;
    }
    
}

void set_push_price(p_stackliste *head, p_stackliste *head_2)
{
    int stack_length_1;
    int stack_length_2;

    stack_length_1 = ft_stacklength(head);
    stack_length_2 = ft_stacklength(head_2);
    
    while (head)
    {
        if (head->above_mediane)
            head->push_price = head->current_position;
        else if(!head->above_mediane)
            head->push_price = stack_length_1 - head->current_position;
        if (head->target_node->above_mediane)
            head->push_price += head->target_node->current_position;
        else if (!head->target_node->above_mediane)
            head->push_price += stack_length_2 - head->target_node->current_position;
        head = head->next;
    }
}



void set_cheapest_one(p_stackliste *head)
{
    p_stackliste *target_node;
    long         bestfit_value;

    bestfit_value = LONG_MAX;
    while (head)
    {
        if (head->push_price < bestfit_value)
        {
            bestfit_value = head->push_price;
            target_node = head;
        }
        head = head->next;
    }
    target_node->cheapest = 1;
}

void set_default(p_stackliste *head)
{
    while (head)
    {
        head->cheapest = 0;
        head = head->next;
    }
}