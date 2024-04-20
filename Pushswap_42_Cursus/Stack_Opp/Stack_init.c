/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:00:29 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/20 13:30:24 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void  set_current_position(linked_list *head)
{
    int compteur;

    compteur = 0;
    if (head == NULL)
        return ;
    while (head)
    {
        head->current_position = compteur;
        head = head->next
    }
}

void  set_mediane_situation(linked_list *head)
{
    int stack_length;
    int compteur;

    compteur = 0;
    stack_length = ft_linkedlength(head);
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

void set_target_node(linked_list *head, linked_list *head_2)
{
    linked_list *temp;
    linked_list *target_node;
    long         last_mini_value;

    last_mini_value = LONG_MAX;
    while (head)
    {
        temp = head;
        while (head_2)
        {
            if (temp->data < head_2->data && temp->data > last_mini_value)
            {
                last_mini_value = head_2->data;
                target_node = temp;
            }
            head = head->next; 
        }
        if (last_mini_value == LONG_MAX)
            head_2->target_node = find_smallest(head);
        else 
            head_2->target_node = target_node;
        head_2 = head_2->next;
    }
}

void set_push_price(linked_list *head, linked_list *head_2)
{
    int stack_length_1;
    int stack_length_2;

    stack_length_1 = ft_linkedlength(head);
    stack_length_2 = ft_linkedlength(head_2);
    while (head)
    {
        if (head->above_mediane == 1)
            head->push_price = head->current_position;
        else if (head->above_mediane == 0)
            head->push_price = (stack_length_1 - head->current_position);
        
    }
}

void set_cheapest_one(linked_list *head)
{
    linked_list *target_node;
    long         bestfit_value;

    bestfit_value = LONG_MAX;
    while (head)
    {
        if (head->push_price < bestfit_value)
        {
            bestfit_value = push_price;
            target_node = head;
        }
        head = head->next;
    }
    target_node->cheapest = 1;
}