/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:42:22 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/19 09:43:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Retrieves the node with the lowest cost in the stack.
 * @param stack The stack to search.
 * @return The node with the lowest cost.
 */
t_stack_node	*get_lc_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->lowest_cost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * Prepares the stack for pushing by rotating it to the top node.
 * @param stack The stack to prepare.
 * @param top_node The node to rotate to the top.
 * @param stack_name The name of the stack ('a' or 'b').
 */
void	push_prep(t_stack_node **stack,	t_stack_node *top_node,
	char stack_name)
{
while (*stack != top_node)
{
if (stack_name == 'a')
{
if (top_node->above_median)
ra(stack);
else
rra(stack);
}
else if (stack_name == 'b')
{
if (top_node->above_median)
rb(stack);
else
rrb(stack);
}
}
}
