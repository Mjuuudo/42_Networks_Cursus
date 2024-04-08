/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:18:04 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/08 16:28:27 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(linked_list **head, linked_list **head_target)
{
    linked_list *current;
    linked_list *target;
    linked_list *temp;
    linked_list *temp_2;
    

    current = *head;
    target = *head_target;
    temp_2 = *head_target;
    temp = target->next;
    target = temp;
    temp = current->next;
    current->next = temp_2;
    
    
    
}