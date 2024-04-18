/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:49:06 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/15 20:27:36 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    linked_list *a;
    linked_list *b;
    int         flag_heapornot;

    a = NULL;
    b = NULL;
    flag_heapornot = 0;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        flag_heapornot = 1;
    } 
    ft_stackinit(&a, argv + 1, flag_heapornot);
    
    if (!ft_issorted(&a))
    {
        if (ft_linkedlength(a) == 2)
            sa(&a);
        else if (ft_linkedlength(a) == 3)
            continue;
        else 
            continue;
    }
    
    return (0);
}