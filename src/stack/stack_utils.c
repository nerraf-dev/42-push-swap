/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:17:16 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/28 11:17:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

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

int	stack_size(t_stack_node *stack)
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
