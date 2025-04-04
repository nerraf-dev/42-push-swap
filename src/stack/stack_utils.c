/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:17:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 14:01:22 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * get_last_node - Get the last node of the stack.
 * @stack: Pointer to the stack.
 *
 * This function returns a pointer to the last node of the stack. If the
 * stack is empty, it returns NULL.
 *
 * Return: Pointer to the last node of the stack.
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
 * free_stack - Free all nodes in the stack.
 * @stack: Pointer to the stack to be freed.
 *
 * This function frees all nodes in the stack and sets the stack pointer
 * to NULL.
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
 * s_size - Get the size of the stack.
 * @stack: Pointer to the stack.
 *
 * This function returns the size of the stack. If a cycle is detected
 * in the stack, it returns -1.
 *
 * Return: Size of the stack, or -1 if a cycle is detected.
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
 * find_min - Find the node with the minimum value in the stack.
 * @stack: Pointer to the stack.
 *
 * This function returns a pointer to the node with the minimum value
 * in the stack. If the stack is empty, it returns NULL.
 *
 * Return: Pointer to the node with the minimum value.
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
 * find_max - Find the node with the maximum value in the stack.
 * @stack: Pointer to the stack.
 *
 * This function returns a pointer to the node with the maximum value
 * in the stack. If the stack is empty, it returns NULL.
 *
 * Return: Pointer to the node with the maximum value.
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
