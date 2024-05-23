/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:43:30 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/22 15:46:43 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void  exit_error(t_stack_list **a, t_stack_list **b, char *holder)
{
        ft_freelinkedlist(a);
        ft_freelinkedlist(b);
        free(holder);
        ft_putstr("Error\n");
        exit (0);
}

void ft_applymovements(t_stack_list **a, t_stack_list **b, char *holder)
{
    if (ft_strcmp("pa\n", holder) == 0)
        pa_b(a, b);
    else if (ft_strcmp("pb\n", holder) == 0)
        pb_b(b, a);
    else if (ft_strcmp("sa\n", holder) == 0)
        sa_b(a);
    else if (ft_strcmp("sb\n", holder) == 0)
        sb_b(b);
    else if (ft_strcmp("ra\n", holder) == 0)
        ra_b(a);
    else if (ft_strcmp("rb\n", holder) == 0)
        rb_b(b);
    else if (ft_strcmp("rr\n", holder) == 0)
        rr_b(a, b);
    else if (ft_strcmp("rra\n", holder) == 0)
        rra_b(a);
    else if (ft_strcmp("rrb\n", holder) == 0)
        rrb_b(a);
    else if (ft_strcmp("rrr\n", holder) == 0)
        rrr_b(a, b);
    else if (ft_strcmp("\n", holder) == 0)
        return ;
    else 
        exit_error(a, b, holder);
    
}


int main(int argc, char **argv)
{
    char    **string;
    char    *holder;
    t_stack_list *a;
    t_stack_list *b;

    a = NULL;
    b = NULL;
    string = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
    if (argc == 2)
	{
		string = ft_split(argv[1], ' ');
		ft_stack_init_1(&a, string, 1);
	}
    else
		ft_stack_init(&a, argv, 0);
    while (1)
    {
        holder = get_next_line(0);
        ft_applymovements(&a, &b, holder);
        if (holder[0] == '\n')
            break ;
    }
    if (ft_checksorted(a) == 1)
        ft_putstr("OK\n");
    else if (ft_checksorted(a) == 0)
        ft_putstr("KO\n");
    ft_freelinkedlist(&a);
    free(holder);
}