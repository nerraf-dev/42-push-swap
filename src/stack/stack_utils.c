/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:17:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:35:50 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Gets the last node of the stack.
 *
 * @param stack The stack to get the last node from.
 * @return t_stack_node* The last node of the stack.
 */
t_stack_node	*get_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Frees all nodes in the stack.
 *
 * @param stack The stack to be freed.
 */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

/**
 * @brief Calculates the size of the stack.
 *
 * @param stack The stack to calculate the size of.
 * @return int The size of the stack, or -1 if a cycle is detected.
 */
int	s_size(t_stack_node *stack)
{
	t_stack_node	*slow;
	t_stack_node	*fast;
	int				size;

	slow = stack;
	fast = stack;
	size = 0;
	while (slow && fast && fast->next)
	{
		size++;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (-1);
	}
	while (slow)
	{
		size++;
		slow = slow->next;
	}
	return (size);
}

/**
 * @brief Finds the node with the minimum value in the stack.
 *
 * @param stack The stack to search.
 * @return t_stack_node* The node with the minimum value.
 */
t_stack_node	*find_min(t_stack_node *stack)
{
	int				min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/**
 * @brief Finds the node with the maximum value in the stack.
 *
 * @param stack The stack to search.
 * @return t_stack_node* The node with the maximum value.
 */
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
