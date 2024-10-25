/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 12:44:22 by sfarren          ###   ########.fr       */
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

t_stack_node	*initialise_stack(int *arr, int size);
void			handle_error(const char *message, char **split, int *int_array);
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
