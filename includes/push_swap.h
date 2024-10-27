/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/27 12:34:43 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"
# include "stack.h"
# include "arg_parser.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

// TODO: delete this function
 void			print_stack(t_stack_node *head, char *name);

// Stack Initialisation Functions
t_stack_node	*initialise_stack(int *arr, int size);
void			initialise_b_nodes(t_stack_node *stack_a,
						t_stack_node *stack_b);
void			initialise_nodes_a(t_stack_node *stack_a,
						t_stack_node *stack_b);
// Error Handling Functions
void			handle_error(const char *message, char **split,
						int *int_array);
// Stack Manipulation Functions
void			free_stack(t_stack_node **stack);
void			push_prep(t_stack_node **stack,	t_stack_node *top_node,
						char stack_name);
void			push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
// Sorting Functions
void			sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			sort_big(t_stack_node **stack_a, t_stack_node **stack_b);

// Sort utils
void			min_to_top(t_stack_node **stack_a);
t_stack_node	*get_lc_node(t_stack_node *stack);
void			current_index(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
int				get_max(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
bool			stack_sorted(t_stack_node	*stack);

#endif
