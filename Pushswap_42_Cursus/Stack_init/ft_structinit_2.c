/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structinit_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:53:21 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/26 16:13:33 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void set_cheapest_one_b(p_stackliste *head)
{
    p_stackliste *target_node;
    long         bestfit_value;

    bestfit_value = LONG_MAX;
    while (head)
    {
        if (head->push_price < bestfit_value)
        {
            bestfit_value = head->push_price;
            target_node = head;
        }
        head = head->next;
    }
    target_node->cheapest = 1;
}
// Probleme en initialization