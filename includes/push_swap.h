/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 15:29:12 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"
# include "stack.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

// Initialization Functions
// void			init_stack_a(t_stack_node **a, int argc, char **argv);
void			initialise_stack(t_stack_node	**stack, int argc, char **argv);

// // Stack Operations
// void			initialise_nodes_a(t_stack_node *stack_a,
// 					t_stack_node *stack_b);
// void			initialise_nodes_b(t_stack_node *stack_a,
// 					t_stack_node *stack_b);
// void			set_push(t_stack_node **stack, t_stack_node *top,
// 					char which_stack);
void			append_node(t_stack_node **stack, int value);
t_stack_node	*get_last_node(t_stack_node *stack);
void			free_stack(t_stack_node	**stack);
int				stack_len(t_stack_node *stack);
// // TODO: remove the print_stack function.remember to remove in the code.
void			print_stack(t_stack_node	*stack, char stack_name);
// int				stack_len(t_stack_node *stack);
// void			current_index(t_stack_node *stack);

// // Validation Functions
// int				check_duplicates(int *arr, int size);
// bool			is_valid_integer(const char *str);
// bool			stack_sorted(t_stack_node *stack);

// // Parsing Functions
// int				*parse_arguments(int argc, char **argv);

// // Sorting Functions
void			sort_two(t_stack_node	**stack);
void			sort_three(t_stack_node	**stack);
// void			sort_big(t_stack_node **stack_a, t_stack_node **stack_b);
// t_stack_node	*find_lowest_cost(t_stack_node *stack);

// // Max/Min Functions
// t_stack_node	*find_min(t_stack_node *stack);
// t_stack_node	*find_max(t_stack_node *stack);

// // Push_Swap Commands
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

// // Move Utilities
// void			rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
// 					t_stack_node *lowest_cost_node);
// void			reverse_rotate_stacks(t_stack_node **stack_a,
// 					t_stack_node **stack_b,	t_stack_node *lowest_cost_node);

#endif
