/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:22:54 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/18 14:32:18 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*low_cost_node;

	low_cost_node = find_lowest_cost(*stack_a);
	if (low_cost_node->above_median && low_cost_node->target->above_median)
		rotate_stacks(stack_a, stack_b, low_cost_node);
	else if (!(low_cost_node->above_median)
		&& !(low_cost_node->target->above_median))
		reverse_rotate_stacks(stack_a, stack_b, low_cost_node);
	set_push(stack_a, low_cost_node, 'a');
	set_push(stack_b, low_cost_node->target, 'b');
	pb(stack_a, stack_b);
}
