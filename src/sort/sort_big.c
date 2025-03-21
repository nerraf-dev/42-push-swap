/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:57:07 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Rotate both stacks until the lowest cost node is at the top.
 *
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param lc_node The lowest cost node.
 */
static void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
				t_stack_node *lc_node)
{
	while (*stack_b != lc_node && *stack_a != lc_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

/**
 * @brief Reverse rotate both stacks until the lowest cost node is at the top.
 *
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param lc_node The lowest cost node.
 */
static void	rev_rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
				t_stack_node *lc_node)
{
	while (*stack_b != lc_node && *stack_a != lc_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

/**
 * @brief Push the lowest cost node from stack a to stack b.
 *
 * @param stack_a The source stack a.
 * @param stack_b The destination stack b.
 */
static void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*lc_node;

	lc_node = get_lc_node(*stack_a);
	if (lc_node->above_median && lc_node->target->above_median)
		rotate_stacks(stack_a, stack_b, lc_node);
	else if (!(lc_node->above_median) && !(lc_node->target->above_median))
		rev_rotate_stacks(stack_a, stack_b, lc_node);
	push_prep(stack_a, lc_node, 'a');
	push_prep(stack_b, lc_node->target, 'b');
	pb(stack_a, stack_b);
}

static void	initial_pushes(t_stack_node **stack_a, t_stack_node **stack_b,
		int *len)
{
	if (*len > 3)
	{
		(*len)--;
		pb(stack_a, stack_b);
	}
	if (*len > 3)
	{
		(*len)--;
		pb(stack_a, stack_b);
	}
	if (*stack_b && (*stack_b)->next
		&& (*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
}

/**
 * @brief Sort a large stack using a combination of algorithms.
 *
 * @param stack_a The stack to sort.
 * @param stack_b The auxiliary stack.
 * @param len The length of the stack.
 */
void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	if (len-- > 3)
		pb(stack_a, stack_b);
	if (len-- > 3)
		pb(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	while (len-- > 3 && !stack_sorted(*stack_a))
	{
		initialise_nodes_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
		initial_len--;
	}
	sort_small(stack_a, stack_b, len + 1);
	while (*stack_b)
	{
		initialise_b_nodes(*stack_a, *stack_b);
		min_to_top(stack_a);
	}
	min_to_top(stack_a);
}
