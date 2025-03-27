/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:48:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/27 13:20:24 by sfarren          ###   ########.fr       */
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
# include "sort_utils.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

typedef void	(*t_op_func)(t_stack_node **, t_stack_node **);

// Error Handling Functions
void	handle_error(bool error, char **split, int *int_array);
void	sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b, int len);
void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b,
			int chunk_size, int num_chunks);
void	sort_radix(t_stack_node **stack_a, t_stack_node **stack_b, int len);

int		ft_strcmp(const char *s1, const char *s2);

#endif
