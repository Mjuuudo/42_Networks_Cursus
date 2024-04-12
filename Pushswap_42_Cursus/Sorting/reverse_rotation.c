/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:40 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/12 18:28:28 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void  ft_reverse_rotation_stack(linked_list **head)
{
    linked_list *target;
    linked_list *last_node;

    if (!last_node)
        return ;
    last_node = ft_addnode(*head);
    last_node->prev->next = NULL;
    last_node->next = (*head);
    last_node->prev = NULL;
    (*head) = last_node;

}
void rra(linked_list *head)
{
    ft_reverse_rotation_stack(*head);
}

void rrb(linked_list *head)
{
    ft_reverse_rotation_stack(*head);
}

void rrr(linked_list **head, linked_list **head_2)
{
    ft_reverse_rotation_stack(*head);
    ft_reverse_rotation_stack(*head_2);
    
}
