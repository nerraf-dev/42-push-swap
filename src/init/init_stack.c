/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 13:57:36 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Creates a new stack node with the given value.
 * @param value The value to assign to the new node.
 * @return The newly created stack node.
 */
static t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * Initializes a stack from an array of integers.
 * @param arr The array of integers.
 * @param size The size of the array.
 * @return The head of the initialized stack.
 */
t_stack_node	*initialise_stack(int *arr, int size)
{
	t_stack_node	*head;
	t_stack_node	*new_node;
	int				i;
	int				*ranks;

	head = NULL;
	new_node = NULL;
	ranks = NULL;
	i = size - 1;
	if (arr == NULL)
		return (NULL);
	ranks = malloc(size * sizeof(int));
	if (!ranks)
		handle_error(true, NULL, arr);
	assign_ranks(arr, ranks, size);
	while (i >= 0)
	{
		new_node = create_node(ranks[i]);
		if (!new_node)
		{
			free_stack(&head);
			return (NULL);
		}
		new_node->next = head;
		if (head != NULL)
			head->prev = new_node;
		head = new_node;
		i--;
	}
	return (head);
}

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
