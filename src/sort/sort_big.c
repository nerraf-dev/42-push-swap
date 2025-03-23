/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 17:38:12 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reindex(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
}

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

