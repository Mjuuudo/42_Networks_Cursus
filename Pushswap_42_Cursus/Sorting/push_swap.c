/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:45:30 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/20 14:30:00 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_swap(linked_list **head, linked_list **head_2)
{
    linked_list *smallest;
    int length;

    length = ft_linkedlength(head);
    while (length > 3)
    {
        pb(head, head_2);
        length--;
    }
    ft_sort_three_nodes(head);
    while (*head_2)
    {
        ft_initialisation(*head, *head_2);
        ft_movenode(head, head_2);
    }
    set_current_position(*head);
    smallest = find_smallest(*head);
    if (smallest->above_median == 1)
        while (*head != smallest)
                ra(head);
    else
        while (*head != smallest)
                rra(head);
}
