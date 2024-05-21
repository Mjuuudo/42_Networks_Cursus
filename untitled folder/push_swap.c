/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:24:49 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/21 10:25:32 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	avoid_norminette(stack_list **a, stack_list **b)
{
	if (ft_checksorted(*a) == 0)
	{
		if (ft_stacklength(*a) == 2)
			sa(a);
		else if (ft_stacklength(*a) == 3)
			ft_sort_three(a);
		else if (ft_stacklength(*a) > 3)
			ft_push_swap(a, b);
	}
	ft_freelinkedlist(a);
}

int	main(int argc, char **argv)
{
	stack_list	*a;
	stack_list	*b;
	char		**s;

	a = NULL;
	b = NULL;
	s = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		s = ft_split(argv[1], ' ');
		ft_stack_init(&a, s, 1);
	}
	else
		ft_stack_init(&a, argv, 0);
	avoid_norminette(&a, &b);
}
