/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:49:06 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 18:24:28 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "stack.h"

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
bool			stack_sorted(t_stack_node *stack);
int				values_in_range(t_stack_node *stack, int *bounds);
void			print_stack(t_stack_node *stack, char *label);

#endif
