/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:39 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/18 14:06:50 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include "../src/libft/libft.h"
# include "stack.h"
// # include "./stack_ops/stack_ops.h"
// # include "./sort/sort.h"

// Stack Ops
void			append_node(t_stack_node **stack, int value);
t_stack_node	*get_last_node(t_stack_node *stack);
void			free_stack(t_stack_node *stack);
void			print_stack(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
// Validation
int				check_duplicates(int *arr, int size);
bool			is_valid_integer(const char *str);
bool			stack_sorted(t_stack_node *stack);
// Parsing
int				*parse_arguments(int argc, char **argv);


// Stack init
void			init_stack_a(t_stack_node **a, int argc, char **argv);

void			sort_two(t_stack_node **stack);
void			sort_three(t_stack_node **stack);
void			sort_big(t_stack_node **stack_a, t_stack_node **stack_b);

// Max Min
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
// Push_Swap_Commands
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			sa(t_stack_node **stack);
void			sb(t_stack_node **stack);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			ra(t_stack_node **stack);
void			rb(t_stack_node **stack);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			rra(t_stack_node **stack);
void			rrb(t_stack_node **stack);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);


#endif
