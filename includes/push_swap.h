/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:56:51 by sfarren          ###   ########.fr       */
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
					int len);
void			sort_radix(t_stack_node **stack_a, t_stack_node **stack_b,
					int len);

// Sort utils
void			min_to_top(t_stack_node **stack_a);
t_stack_node	*get_lc_node(t_stack_node *stack);
void			current_index(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
int				get_max(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
int				s_size(t_stack_node *stack);
bool			stack_sorted(t_stack_node	*stack);

#endif
