/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:38:57 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/08 14:09:10 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_stackinit(linked_list **head, char **argv, int flag_heapornot)
{
    long number;
    int compteur;

    conmpteu = 0;
    while (argv[compteur])
    {
        if (syntaxe_error(*argv[compteur]))
            ft_freeerrors(head, argv, flag_heapornot);
        number = ft_atol(argv[compteur]);
        if (number >= INT_MAX && number <= INT_MIN)
            ft_freeerrors(head, argv, flag_heapornot);
        if (ft_checkrepetition(head, (int)number))
            ft_freeerrors(head, argv, flag_heapornot);
        ft_addnode(head, (int)number);
        compteur++;
    }
    if (flag_heapornot)
        ft_freeheapargv(argv);
}