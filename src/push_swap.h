/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:39 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/14 13:45:41 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
// # include <stdbool.h>
# include "./libft/libft.h"
// # include "./ranking/c_sort.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

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

// Stack Operations
// void	swap(t_stack *stack);
// void	rotate(t_stack *stack);
// void	reverse_rotate(t_stack *stack);
// void	ss(t_stack *a, t_stack *b);
// void	rr(t_stack *a, t_stack *b);
// void	rrr(t_stack *a, t_stack *b);



// TODO: This one wil have to change
int	push_swap(int *arr, int length);

#endif
