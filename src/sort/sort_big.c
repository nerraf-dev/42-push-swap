/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 19:58:43 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * reindex - Updates the indices of the nodes in both stacks.
 * @stack_a: Pointer to the first stack.
 * @stack_b: Pointer to the second stack.
 *
 * This function recalculates and updates the indices of all nodes in
 * both stack_a and stack_b.
 */
static void	reindex(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
}

/**
 * sort_chunk - Sorts a chunk of the stack within specified bounds.
 * @stack_a: Pointer to the first stack.
 * @stack_b: Pointer to the second stack.
 * @bounds: Array containing the lower and upper bounds of the chunk.
 *
 * This function sorts a chunk of the stack defined by the bounds array.
 * It moves nodes within the bounds from stack_a to stack_b, ensuring
 * that the nodes are moved in the correct order.
 */
static void	sort_chunk(t_stack_node **stack_a, t_stack_node **stack_b,
			int *bounds)
{
	t_stack_node	*node;
	t_stack_node	*rev_node;
	t_stack_node	*lc_node;

	while (values_in_range(*stack_a, bounds))
	{
		node = find_in_range(*stack_a, bounds);
		rev_node = rev_find_in_range(*stack_a, bounds);
		if (node->index < s_size(*stack_a) - rev_node->index)
			lc_node = node;
		else
			lc_node = rev_node;
		if (*stack_b == NULL)
		{
			move_to_top(stack_a, NULL, lc_node, NULL);
			pb(stack_a, stack_b);
		}
		else
		{
			set_target(lc_node, stack_b);
			move_to_top(stack_a, stack_b, lc_node, lc_node->target);
			pb(stack_a, stack_b);
		}
		reindex(*stack_a, *stack_b);
	}
}

/**
 * sort_big - Sorts a large stack using a chunk-based approach.
 * @stack_a: Pointer to the first stack.
 * @stack_b: Pointer to the second stack.
 * @chunk_size: Size of each chunk.
 * @num_chunks: Number of chunks to divide the stack into.
 *
 * This function sorts a large stack by dividing it into smaller chunks
 * and sorting each chunk individually. It then moves the sorted chunks
 * back to the original stack in the correct order.
 */
void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b,
			int chunk_size, int num_chunks)
{
	int				chunk;
	int				bounds[2];
	t_stack_node	*lc_node;

	chunk = 0;
	while (chunk < num_chunks)
	{
		bounds[0] = chunk * chunk_size;
		bounds[1] = ((chunk + 1) * chunk_size) - 1;
		sort_chunk(stack_a, stack_b, bounds);
		chunk++;
	}
	while (*stack_b)
	{
		lc_node = find_max(*stack_b);
		move_to_top(NULL, stack_b, NULL, lc_node);
		current_index(*stack_a);
		current_index(*stack_b);
		pa(stack_a, stack_b);
	}
}
