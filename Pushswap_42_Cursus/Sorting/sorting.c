/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:16:37 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/20 13:37:11 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

linked_list *find_highest(linked_list *head)
{
    linked_list *highest_one;
    int          high_value;

    if (head == NULL)
        return (NULL);
    high_value = INT_MIN;
    while (head)
    {
        if (head->data > high_value)
        {
            high_value = head->data;
            highest_one = head;
        }
        head = head->next;
    }    
    return (highest_one);
}

linked_list *find_smallest(linked_list *head)
{
    linked_list *smallest_one;
    long          smallest_value;

    smallest_value = LONG_MAX;
    while (head)
    {
        if (smallest_value > head->data)
        {
            smallest_one = head;
            smallest_value = head->data;
        }
        head = head->next;
    }
    return (smallest_one);
    
}

void ft_sort_three_nodes(linked_list **head)
{
    linked_list *highest_one;

    highest_one = find_highest(*head);
    if (*head == highest_one)
        ra(head);
    else if ((*head)->next == highest_one)
        rra(head);
    if ((*head)->data > (*head)->next->data)
        sa(head);
}

linked_list *ft_returncheapest(linked_list *head)
{
    linked_list *cheapest;

    while (head)
    {
        if (head->cheapest = 1)
        {
            cheapest = head;
        }
        head = head -> next; 
    }
    return (cheapest);
}