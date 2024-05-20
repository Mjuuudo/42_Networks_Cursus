/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:20:11 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/20 14:24:15 by abait-ou         ###   ########.fr       */
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

}						stack_list;

// Outils Used for parsing

char					**ft_split(char const *s, char c);
long long				ft_atol(const char *str);
void					ft_putstr(char *s);

//  Stack Creation

void					ft_stack_init(stack_list **stack, char **argv,
							int flag_heapornpot);
void					ft_addnode(stack_list **stack, int data);
stack_list				*ft_getlastnode(stack_list *stack);
int						ft_checksorted(stack_list *stack_a);
int						ft_stacklength(stack_list *stack_a);

// Error handling

int						ft_checkrepetition(stack_list *head, int number);
void					ft_freelinkedlist(stack_list **head);
void					ft_freeheapargv(char **argv);
void					ft_freeerrors(stack_list **head, char **argv,
							int flag_heapornot);
int						syntaxe_error(const char *string);

// Movements

void					pa(stack_list **a, stack_list **b);
void					pb(stack_list **b, stack_list **a);
void					rra(stack_list **a);
void					rrb(stack_list **b);
void					rrr(stack_list **a, stack_list **b);
void					ra(stack_list **a);
void					rb(stack_list **b);
void					rr(stack_list **a, stack_list **b);
void					sa(stack_list **a);
void					sb(stack_list **b);
void					ss(stack_list **a, stack_list **b);

// Sorting Function

void					ft_sort_three(stack_list **a);
stack_list				*find_min(stack_list *stack);
stack_list				*find_max(stack_list *stack);

// from a to b

void					ft_push_price(stack_list **a, stack_list **b);
void					ft_set_target_a(stack_list *a, stack_list *b);
void					current_index(stack_list *stack);
void					ft_set_cheapest(stack_list *stack);
void					init_nodes_a(stack_list *a, stack_list *b);
void					prep_for_push(stack_list **stack, stack_list *top_node,
							char stack_name);
stack_list				*ft_get_cheapest(stack_list *stack);
void					ft_push_swap(stack_list **a, stack_list **b);
void					init_nodes_b(stack_list *a, stack_list *b);
void					max_on_top(stack_list **b);
void					ft_calc_movtg(stack_list **stack_a,
							stack_list **stack_b, stack_list *node);
stack_list				*ft_calc_lessmoves(stack_list **stack_a);
void					min_on_top(stack_list **a);

#endif