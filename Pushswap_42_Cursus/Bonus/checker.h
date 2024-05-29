/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:07:12 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/29 16:04:53 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl/get_next_line.h"
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct stack_list
{
	int					data;
	int					above_mediane;
	int					current_position;
	int					push_cost;
	int					cheapest;
	struct stack_list	*target_node;
	struct stack_list	*next;
	struct stack_list	*prev;

}						t_stack_list;

// Handling Errors Functions

int						ft_checkrepetition(t_stack_list *head, int number);
void					ft_freelinkedlist(t_stack_list **head);
void					ft_freeheapargv(char **argv);
void					ft_freeerrors(t_stack_list **head, char **argv,
							int flag_heapornot);
int						syntaxe_error(const char *string);

// Stack Creation Functions

int						ft_stacklength(t_stack_list *stack_a);
int						ft_checksorted(t_stack_list *stack_a);
t_stack_list			*ft_getlastnode(t_stack_list *stack);
void					ft_addnode(t_stack_list **stack, int data);
void					ft_stack_init(t_stack_list **a, char **argv,
							int flag_heapornot);
void					ft_creationofstack(t_stack_list **a, char *buffer,
							int flag_heapornot, char **buffer_big);
int						ft_checkargtype(char *arg);
void					ft_hardcreation(t_stack_list **a, char *arg,
							int flag_heapornot);
void					ft_stack_init_1(t_stack_list **a, char **argv,
							int flag_heapornot);
int						ft_check_space(const char *s);

// Outils Used In Project

long long				ft_atol(const char *str);
void					ft_putstr(char *s);
char					**ft_split(char const *s, char c);
int						ft_strcmp(const char *s1, const char *s2);
void					avoid_norminette(t_stack_list **a, t_stack_list **b);

// Sorting Movements Functions

void					ft_applymovements(t_stack_list **a, t_stack_list **b,
							char *holder);
void					exit_error(t_stack_list **a, t_stack_list **b,
							char *holder);
void					pa(t_stack_list **a, t_stack_list **b);
void					pb(t_stack_list **b, t_stack_list **a);
void					rra(t_stack_list **a);
void					rrb(t_stack_list **b);
void					rrr(t_stack_list **a, t_stack_list **b);
void					ra(t_stack_list **a);
void					rb(t_stack_list **b);
void					rr(t_stack_list **a, t_stack_list **b);
void					sa(t_stack_list **a);
void					sb(t_stack_list **b);
void					ss(t_stack_list **a, t_stack_list **b);
void					practice(t_stack_list **a, t_stack_list **b);

#endif