/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:08:26 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 14:02:55 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * rotate_stack_a - Rotate stack A based on the node's position.
 * @stack_a: Double pointer to stack A.
 * @node_a: Pointer to the node in stack A.
 *
 * This function rotates stack A based on the node's position relative to
 * the median.
 */
static void	rotate_stack_a(t_stack_node **stack_a, t_stack_node *node_a)
{
	if (node_a->above_median)
		ra(stack_a);
	else
		rra(stack_a);
}

/**
 * rotate_stack_b - Rotate stack B based on the node's position.
 * @stack_b: Double pointer to stack B.
 * @node_b: Pointer to the node in stack B.
 *
 * This function rotates stack B based on the node's position relative to
 * the median.
 */
static void	rotate_stack_b(t_stack_node **stack_b, t_stack_node *node_b)
{
	if (node_b->above_median)
		rb(stack_b);
	else
		rrb(stack_b);
}

/**
 * move_to_top - Move nodes to the top of their respective stacks.
 * @stack_a: Double pointer to stack A.
 * @stack_b: Double pointer to stack B.
 * @node_a: Pointer to the node in stack A.
 * @node_b: Pointer to the node in stack B.
 *
 * This function moves the specified nodes to the top of their respective
 * stacks by rotating the stacks appropriately.
 */
void	move_to_top(t_stack_node **stack_a, t_stack_node **stack_b,
				t_stack_node *node_a, t_stack_node *node_b)
{
	while ((stack_a && *stack_a != node_a) || (stack_b && *stack_b != node_b))
	{
		if ((stack_a && *stack_a != node_a) && (stack_b && *stack_b != node_b))
		{
			if (node_a->above_median && node_b && node_b->above_median)
				rr(stack_a, stack_b);
			else if (!node_a->above_median && node_b && !node_b->above_median)
				rrr(stack_a, stack_b);
			else
			{
				rotate_stack_a(stack_a, node_a);
				rotate_stack_b(stack_b, node_b);
			}
		}
		else if (stack_a && *stack_a != node_a)
		{
			rotate_stack_a(stack_a, node_a);
		}
		else if (stack_b && *stack_b != node_b)
		{
			rotate_stack_b(stack_b, node_b);
		}
	}
}
