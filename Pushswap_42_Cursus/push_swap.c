/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:01:35 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/01 16:04:09 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
    
    p_stackliste    *a;
    p_stackliste    *b;
    int              flag_heapornpot;

    a = NULL;
    b = NULL;
    flag_heapornpot = 0;
    if (argc == 1 || (argc == 2 && !(argv[1][0])))
            return (-1);
    if (argc == 2)
    {
        argv = ft_split (argv[1], ' ');
        flag_heapornpot = 1;
        // int compteur = 0;
        // while(argv[compteur + 1])
        // {
        //     printf("argv : %s\n", argv[compteur + 1]);
        //     compteur++;
        // }
        // printf("arg  solde %d\n", compteur);
        ft_stack_init(&a, argv, flag_heapornpot);
    }
    else
        ft_stack_init(&a, argv + 1, flag_heapornpot);
    if ((ft_checksorted(a)) == 0)
    {
        if (ft_stacklength(a) ==  2)
            sa(&a);
        else if (ft_stacklength(a) == 3)
            ft_sorththree(&a);
        else
            push_swap(&a, &b);
    } 
    ft_freelinkedlist(&a);
    return (0);
}