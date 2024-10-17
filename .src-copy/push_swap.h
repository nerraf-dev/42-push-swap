/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:39 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 11:55:26 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include "./libft/libft.h"
// # include "./stack_ops/stack_ops.h"
// # include "./sort/sort_ops.h"
// # include "stack.h"

/**
 * @brief Checks if the given string represents a valid integer.
 *
 * This function verifies if the input string is a valid integer representation.
 *
 * @param str The string to be checked.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int		is_valid_integer(const char *str);

// *** LIBFT ***
/**
 * @brief Converts a string to an integer.
 *
 * This function converts the input string to an integer. It handles optional
 * leading whitespace and an optional plus or minus sign.
 *
 * @param str The string to be converted.
 * @return The integer value of the string.
 */
int		ft_atoi(const char *str);

// TODO: This one wil have to change
int		push_swap(int *arr, int length);

#endif
