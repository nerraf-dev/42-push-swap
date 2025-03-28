/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 18:19:03 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Creates a new stack node with the given value and index.
 * @param value The value to assign to the new node.
 * @param index The index to assign to the new node.
 * @return The newly created stack node.
 */
static t_stack_node	*create_node(int value, int index)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * Initializes an array of ranks based on the given array.
 * @param arr The array of integers.
 * @param size The size of the array.
 * @return The array of ranks.
 */
static int	*init_ranks(int *arr, int size)
{
	int	*ranks;

	ranks = malloc(size * sizeof(int));
	if (!ranks)
		handle_error(true, NULL, arr);
	assign_ranks(arr, ranks, size);
	return (ranks);
}

/**
 * Builds the stack by adding a new node with the given rank and index.
 * @param head The head of the stack.
 * @param rank The rank to assign to the new node.
 * @param i The index to assign to the new node.
 * @return The newly created stack node.
 */
static t_stack_node	*build_stack(t_stack_node **head, int rank, int i)
{
	t_stack_node	*new_node;

	new_node = create_node(rank, i);
	if (!new_node)
	{
		free_stack(head);
		return (NULL);
	}
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
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
	int				*ranks;
	int				i;

	if (arr == NULL)
		return (NULL);
	head = NULL;
	ranks = init_ranks(arr, size);
	if (!ranks)
		return (NULL);
	i = size - 1;
	while (i >= 0)
	{
		if (!build_stack(&head, ranks[i], i))
			return (NULL);
		i--;
	}
	free(ranks);
	return (head);
}
