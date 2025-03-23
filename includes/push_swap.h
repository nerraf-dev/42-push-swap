/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 17:40:00 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/src/libft.h"
# include "stack.h"
# include "arg_parser.h"
# include "ranking.h"
# include "commands.h"
# include "initialisation.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

// Error Handling Functions
void			handle_error(bool error, char **split, int *int_array);

// Stack Manipulation Functions
void			free_stack(t_stack_node **stack);
void			push_prep(t_stack_node **stack,	t_stack_node *top_node,
					char stack_name);
void			push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);

// Sorting Functions
void			sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b,
					int len);
void			sort_big(t_stack_node **stack_a, t_stack_node **stack_b,
					int chunk_size, int num_chunks);
void			sort_radix(t_stack_node **stack_a, t_stack_node **stack_b,
					int len);

// Sort utils
void			current_index(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_in_range(t_stack_node *stack, int *bounds);
t_stack_node	*get_lc_node(t_stack_node *stack);
void			min_to_top(t_stack_node **stack_a);
void			move_to_top(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *lc_node, t_stack_node *target);
t_stack_node	*rev_find_in_range(t_stack_node *stack, int *bounds);
int				s_size(t_stack_node *stack);
void			set_target(t_stack_node *node, t_stack_node **stack);
bool			stack_sorted(t_stack_node	*stack);
int				values_in_range(t_stack_node *stack, int *bounds);
// TODO: Remove
void			print_stack(t_stack_node *stack, char *label);



#endif
