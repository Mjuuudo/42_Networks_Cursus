/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:18:04 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/12 17:17:09 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void ft_push_opperation(linked_list **destination, linked_list **source)
{
    linked_list *target_node;

    if (!(*source))
        return ;
    target_node = *source;
    *source = (*source)->next;
    if (*src)
        (*source)->prev = NULL;
    if((*destination) == NULL)
    {
        (*destination) = target_node;
        target_node->next = NULL;
        target_node->prev = NULL; 
    }
    else
    {
        target_node->next = (*destination);
        target_node->next->prev = target_node;
        *destination = target_node;
    }
    
    
}

void pa(linked_list **head, linked_list **head_target)
{
    ft_push_opperation(head_target, head);
}

void pb(linked_list **head, linked_list **head_target)
{
    ft_push_opperation(head, head_target);
}