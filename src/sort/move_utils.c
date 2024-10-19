/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:28:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/18 19:52:27 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_stacks(t_stack_node **stack_a,
						t_stack_node **stack_b,
						t_stack_node *lowest_cost_node)
{
	while (*stack_b != lowest_cost_node->target
		&& *stack_a != lowest_cost_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	reverse_rotate_stacks(t_stack_node **stack_a,
								t_stack_node **stack_b,
								t_stack_node *lowest_cost_node)
{
	while (*stack_b != lowest_cost_node->target
		&& *stack_a != lowest_cost_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}
