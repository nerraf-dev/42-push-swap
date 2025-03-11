/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/11 13:02:49 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*initialise_stack(int *arr, int *ranks, int size)
{
	t_stack_node	*head;
	t_stack_node	*new_node;
	int				i;

	head = NULL;
	if (arr == NULL)
		return (head);
	i = size - 1;
	while (i >= 0)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (!new_node)
			return (NULL);
		new_node->value = arr[i];
		new_node->rank = ranks[i];
		new_node->next = head;
		new_node->prev = NULL;
		if (head != NULL)
			head->prev = new_node;
		head = new_node;
		i--;
	}
	return (head);
}

/**
 * @brief Retrieves the node with the lowest cost from the stack.
 *
 * This function traverses the given stack and returns the first node
 * that has the `lowest_cost` flag set to true. If no such node is found,
 * or if the stack is empty, the function returns NULL.
 *
 * @param stack A pointer to the head of the stack.
 * @return pointer to node with the lowest cost, or NULL if no node exists.
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
