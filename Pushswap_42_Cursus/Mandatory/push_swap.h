/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:20:11 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/23 13:13:01 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// Outils Used for parsing

char					**ft_split(char const *s, char c);
long long				ft_atol(const char *str);
void					ft_putstr(char *s);

//  Stack Creation

void					ft_stack_init(t_stack_list **stack, char **argv,
							int flag_heapornpot);
void					ft_addnode(t_stack_list **stack, int data);
t_stack_list			*ft_getlastnode(t_stack_list *stack);
int						ft_checksorted(t_stack_list *stack_a);
int						ft_stacklength(t_stack_list *stack_a);

// Error handling

int						ft_checkrepetition(t_stack_list *head, int number);
void					ft_freelinkedlist(t_stack_list **head);
void					ft_freeheapargv(char **argv);
void					ft_freeerrors(t_stack_list **head, char **argv,
							int flag_heapornot);
int						syntaxe_error(const char *string);

// Movements

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

// Sorting Function

void					ft_sort_three(t_stack_list **a);
t_stack_list			*find_min(t_stack_list *stack);
t_stack_list			*find_max(t_stack_list *stack);

// from a to b

void					ft_push_price(t_stack_list **a, t_stack_list **b);
void					ft_set_target_a(t_stack_list *a, t_stack_list *b);
void					current_index(t_stack_list *stack);
void					ft_set_cheapest(t_stack_list *stack);
void					init_nodes_a(t_stack_list *a, t_stack_list *b);
void					prep_for_push(t_stack_list **stack,
							t_stack_list *top_node, char stack_name);
t_stack_list			*ft_get_cheapest(t_stack_list *stack);
void					ft_push_swap(t_stack_list **a, t_stack_list **b);
void					init_nodes_b(t_stack_list *a, t_stack_list *b);
void					max_on_top(t_stack_list **b);
void					ft_calc_movtg(t_stack_list **stack_a,
							t_stack_list **stack_b, t_stack_list *node);
t_stack_list			*ft_calc_lessmoves(t_stack_list **stack_a);
void					min_on_top(t_stack_list **a);

void					ft_creationofstack(t_stack_list **a, char *buffer,
							int flag_heapornot, char **buffer_big);
int						ft_checkargtype(char *arg);
void					ft_hardcreation(t_stack_list **a, char *arg,
							int flag_heapornot);
void					ft_stack_init_1(t_stack_list **a, char **argv,
							int flag_heapornot);
int  					ft_check_space(const char *s);

#endif