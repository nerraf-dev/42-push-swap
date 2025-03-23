/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:08:26 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 14:42:27 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_stack_a(t_stack_node **stack_a, t_stack_node *node_a)
{
	if (node_a->above_median)
		ra(stack_a);
	else
		rra(stack_a);
}

static void	rotate_stack_b(t_stack_node **stack_b, t_stack_node *node_b)
{
	if (node_b->above_median)
		rb(stack_b);
	else
		rrb(stack_b);
}

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
