/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:06:37 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/24 14:05:36 by abait-ou         ###   ########.fr       */
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
        pa(a, b);
    
    else if (ft_strcmp("pb\n", holder) == 0)
        pb(b, a);

    else if (ft_strcmp("sa\n", holder) == 0)
        sa(a);
    
    else if (ft_strcmp("sb\n", holder) == 0)
        sb(b);
    
    else if (ft_strcmp("ra\n", holder) == 0)
        ra(a);
    
    else if (ft_strcmp("rb\n", holder) == 0)
        rb(b);
    
    else if (ft_strcmp("rr\n", holder) == 0)
        rr(a, b);
    
    else if (ft_strcmp("rra\n", holder) == 0)
        rra(a);
    
    else if (ft_strcmp("rrb\n", holder) == 0)
        rrb(b);
    
    else if (ft_strcmp("rrr\n", holder) == 0)
        rrr(a, b);
    else 
        exit_error(a, b, holder);
}

void    practice(t_stack_list **a, t_stack_list **b)
{
    char *holder;
    while (1)
    {
      holder = get_next_line(0);
      if(!holder)
        break ;
      ft_applymovements(a, b, holder);
      free(holder);
    }
    free(holder);
}




int main(int argc, char **argv)
{
    t_stack_list *a;
    t_stack_list *b;
    char         **string;

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
  if (!ft_checksorted(a))
    practice(&a, &b);
  if (ft_checksorted(a) && !b)
      ft_putstr("OK\n");
  else
      ft_putstr("KO\n");
  ft_freelinkedlist(&a);
  ft_freelinkedlist(&b);  
  return 0;  
}