/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:49:28 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Creates a new stack node with the given value.
 *
 * @param value The value to be assigned to the new node.
 * @return t_stack_node* Pointer to the newly created node, or NULL if
 * allocation fails.
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
 * @brief Initializes a stack from an array of integers.
 *
 * @param arr The array of integers to initialize the stack with.
 * @param size The size of the array.
 * @return t_stack_node* Pointer to the head of the initialized stack, or
 * NULL if allocation fails.
 */
t_stack_node	*initialise_stack(int *arr, int size)
{
	t_stack_node	*head;
	t_stack_node	*new_node;
	int				i;

	head = NULL;
	new_node = NULL;
	i = size - 1;
	if (arr == NULL)
		return (NULL);
	while (i >= 0)
	{
		new_node = create_node(arr[i]);
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
 * @brief Retrieves the node with the lowest cost from the stack.
 *
 * @param stack The stack to search through.
 * @return t_stack_node* Pointer to the node with the lowest cost, or NULL if
 * no such node exists.
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
 * @brief Prepares the stack for a push operation by rotating it until the
 * top_node is at the top.
 *
 * @param stack The stack to be prepared.
 * @param top_node The node to be moved to the top.
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
