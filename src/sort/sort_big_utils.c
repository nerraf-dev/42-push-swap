/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:08:26 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 18:14:25 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Finds the target node in the stack that has the highest value less than the
 * given node's value.
 *
 * @param node The node to compare against.
 * @param stack The stack to search within.
 * @return The target node or NULL if no such node exists.
 */
static t_stack_node	*find_target_node(t_stack_node *node, t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*target;

	current = stack;
	target = NULL;
	while (current)
	{
		if (current->value < node->value)
		{
			if (!target || current->value > target->value)
				target = current;
		}
		current = current->next;
	}
	return (target);
}

/**
 * Sets the target node for the given node in the stack.
 *
 * @param node The node to set the target for.
 * @param stack The stack to search within.
 */
void	set_target(t_stack_node *node, t_stack_node **stack)
{
	t_stack_node	*target;
	t_stack_node	*min;
	t_stack_node	*max;

	if (!node || !stack || !*stack)
		return ;
	min = find_min(*stack);
	max = find_max(*stack);
	if (node->value > max->value)
		target = min;
	else if (node->value < min->value)
		target = max;
	else
	{
		target = find_target_node(node, *stack);
		if (!target)
			target = min;
	}
	node->target = target;
}

/**
 * Checks if there are any values within the given range in the stack.
 *
 * @param stack The stack to search within.
 * @param bounds The range bounds [min, max].
 * @return 1 if there are values in range, 0 otherwise.
 */
int	values_in_range(t_stack_node *stack, int *bounds)
{
	while (stack)
	{
		if (stack->value >= bounds[0] && stack->value <= bounds[1])
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * Finds the first node in the stack with a value within the given range.
 *
 * @param stack The stack to search within.
 * @param bounds The range bounds [min, max].
 * @return The first node in range or NULL if no such node exists.
 */
t_stack_node	*find_in_range(t_stack_node *stack, int *bounds)
{
	while (stack)
	{
		if (stack->value >= bounds[0] && stack->value <= bounds[1])
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * Finds the last node in the stack with a value within the given range.
 *
 * @param stack The stack to search within.
 * @param bounds The range bounds [min, max].
 * @return The last node in range or NULL if no such node exists.
 */
t_stack_node	*rev_find_in_range(t_stack_node *stack, int *bounds)
{
	t_stack_node	*last;

	last = NULL;
	while (stack)
	{
		if (stack->value >= bounds[0] && stack->value <= bounds[1])
			last = stack;
		stack = stack->next;
	}
	return (last);
}
