/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:27:38 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/13 13:05:41 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"


void ft_rotation_stack(linked_list **head)
{
    linked_list *target;
    linked_list *last_node;

    if (*head == NULL)
        return ;
    target = (*head);
    *head = (*head)->next;
    (*head)->prev = NULL;
    last_node = ft_lastnode(*head);
    target->prev = last_node;
    last_node->next = target;
    target->next = NULL;
}
void ra(linked_list **head)
{
    ft_rotation_stack(*head);
}
void rb(linked_list **head)
{
    ft_rotation_stack(*head);
}

