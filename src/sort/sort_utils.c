/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:34:31 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 20:00:00 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Assigns an index to each node in the stack and determines if the node
 *        is above the median.
 *
 * Iterates through the given stack and assigns an index to each
 * node starting from 0. It also determines if the node's index is above the
 * median index of the stack. If the index is less than or equal to the median
 * index, the node's `above_median` attribute is set to true, otherwise it is
 * set to false.
 *
 * @param stack A pointer to the head of the stack.
 */
void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = s_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median - 1)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/**
 * Check if the stack is sorted in ascending order.
 * @param stack The stack to check.
 * @return True if the stack is sorted, false otherwise.
 */
bool	stack_sorted(t_stack_node	*stack)
{
	t_stack_node	*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

/**
 * Move the minimum value in the stack to the top.
 * @param stack_a The stack to modify.
 */
void	min_to_top(t_stack_node **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

/**
 * Get the size of the stack.
 * @param stack The stack to measure.
 * @return The number of elements in the stack.
 */
int	stack_size(t_stack_node *stack)
{
	int				size;
	t_stack_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
