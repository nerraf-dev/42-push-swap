/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:57:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 19:50:31 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sets the target node in stack_a for each node in stack_b.
 * @param stack_a The stack A to process.
 * @param stack_b The stack B to process.
 */
static void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	int				target_index;

	while (stack_b)
	{
		target_index = INT_MAX;
		target = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < target_index)
			{
				target_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target_index == INT_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

/**
 * Initializes nodes in stack_b with index and target.
 * @param stack_a The stack A to use for target calculation.
 * @param stack_b The stack B to initialize.
 */
void	initialise_b_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
