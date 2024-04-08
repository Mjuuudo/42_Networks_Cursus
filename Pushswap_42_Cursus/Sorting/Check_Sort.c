/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_Sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:43:06 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/08 15:51:40 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int  ft_issorted(linked_list **head)
{
    linked_list *current;
    linked_list *next;

    if (head == NULL)
        return (1);
    current = *head;
    next = current->next;
    while (next)
    {   
        if (current->data > next->data)
            return (0);
        current = current->next;
        next = next->next;
    }
    return (1);
}