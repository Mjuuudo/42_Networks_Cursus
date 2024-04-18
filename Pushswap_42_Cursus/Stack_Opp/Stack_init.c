/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:00:29 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/15 19:49:20 by abait-ou         ###   ########.fr       */
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