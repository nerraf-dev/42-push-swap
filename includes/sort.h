/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:58:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/07 12:52:00 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

// Sorting Functions
void			sort_small(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_big(t_stack_node **stack_a, t_stack_node **stack_b);

// Max Min
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

void			rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *lc_node);
void			rev_rotate_stacks(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *lc_node);
#endif
