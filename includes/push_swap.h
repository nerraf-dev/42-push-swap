/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 14:48:08 by sfarren          ###   ########.fr       */
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

// Initialization Functions

// TODO: delete this function
 void			print_stack(t_stack_node *head, char *name);

t_stack_node	*initialise_stack(int *arr, int size);
void			initialise_nodes_b(t_stack_node *stack_a,
						t_stack_node *stack_b);
void			initialise_nodes_a(t_stack_node *stack_a,
						t_stack_node *stack_b);
void			handle_error(const char *message, char **split,
						int *int_array);
void			free_stack(t_stack_node **stack);
void			sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b);

int				stack_len(t_stack_node *stack);

void			push_prep(t_stack_node **stack,	t_stack_node *top_node,
						char stack_name);
t_stack_node	*get_cost(t_stack_node *stack);
void			current_index(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
// // Argument Parser Functions (arg_parser.h)
// int		*argument_parser(int argc, char **argv, int *arr_size);
// int		*parse_arguments(int argc, char **argv, int *arr_size);
// int		*parse_single_arg(char **argv, int *arr_size);
// void	handle_error(const char *message, char **split, int *int_array);
// void	free_split(char **split);
// int		int_array_length(int *int_array);
// int		is_valid_int(const char *str);
// int		has_duplicates(int *arr, int size);

#endif
