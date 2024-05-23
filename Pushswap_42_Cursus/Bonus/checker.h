/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:43:40 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/22 15:03:04 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include "../Mandatory/push_swap.h"
#include "get_next_line_bonus.h"

int	ft_strcmp(char *s1, char *s2);
void	pa_b(t_stack_list **a, t_stack_list **b);
void	pb_b(t_stack_list **b, t_stack_list **a);
void	rra_b(t_stack_list **a);
void	rrb_b(t_stack_list **b);
void	rrr_b(t_stack_list **a, t_stack_list **b);
void	ra_b(t_stack_list **a);
void	rb_b(t_stack_list **b);
void	rr_b(t_stack_list **a, t_stack_list **b);
void	sa_b(t_stack_list **a);
void	sb_b(t_stack_list **b);
void	ss_b(t_stack_list **a, t_stack_list **b);





#endif