/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:39 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/20 18:13:03 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(linked_list **head)
{
    linked_list *current;
    linked_list *next;
    linked_list *temp;
    linked_list *last;
    
    if (ft_linkedlength(*head) == 1 || head == NULL)
        return ;
    current = *head;
    next = current->next;
    last = next->next;
    temp = current;
    *head = next;
    next->next = temp;
    next->prev = NULL;
    current->next = last;
    current->prev = next;
}

void sb(linked_list **head)
{
    linked_list *current;
    linked_list *next;
    linked_list *temp;
    linked_list *last;

    if (ft_linkedlength(*head) == 1 || head == NULL)
        return ;
    current = *head;
    next = current->next;
    last = next->next;
    temp = current;
    *head = next;
    next->next = temp;
    next->prev = NULL;
    current->next = last;
    current->prev = next;
}
void ss(linked_list **head)
{
    sa(*head);
    sb(*head);
}