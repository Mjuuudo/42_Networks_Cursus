/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:22:27 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/20 14:19:58 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
static void rotate_both(linked_list **head, linked_list **head_2, linked_list *cheapest_node)
{
    while (*head != cheapest_node->target_node && *head_2 != cheapest_node)
            rr(head,  head_2);
    set_current_position(*head);
    set_current_position(*head_2);
}

static void reverse_rotate_both(linked_list **head, linked_list **head_2, linked_list *cheapest_node)
{
    while (*head != cheapest_node->target_node && *head_2 != cheapest_node)
            rrr(head,  head_2);
    set_current_position(*head);
    set_current_position(*head_2);
}

void    finish_rotation(linked_list **head, linked_list **top_node, char stack_name)
{
    while (head != top_node)
    {
        if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(head);
			else
				rra(head);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(head);
			else
				rrb(head);
		}	 
    }
}

void ft_movenode(linked_list **head, linked_list **head_2)
{
    linked_list *cheapest;

    cheapest = ft_returncheapest(*head_2);
    if (cheapest->above_mediane == 1 && cheapest->target_node->above_mediane == 1)
    {
        rotate_both(head, head_2, cheapest);
    }
    else if (!(cheapest->above_mediane == 1) && !(cheapest->target_node->above_mediane == 1))
    {
        reverse_rotate_both(head, head_2, cheapest);
    }
    finish_rotation(head, cheapest, 'b');
    finish_rotation(head_2, cheapest->target, 'a');
    pa(head, head_2);
}

void ft_initialisation(linked_list *head, linked_list *head_2)
{
    set_current_position(head);
    set_current_position(head_2);
    set_mediane_situation(head);
    set_mediane_situation(head_2);
    set_target_node(head, head_2);
    set_push_price(head, head_2);
    set_cheapest_one(head_2);
}