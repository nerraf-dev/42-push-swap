/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/09 15:17:00 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	stack_size(t_stack_node *stack)
{
	int				size;
	t_stack_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

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

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int		len;
	// int		initial_len;

	len = stack_size(*stack_a);
	initial_pushes(stack_a, stack_b, &len);
	// initial_len = len;
	while (len > 3 && !stack_sorted(*stack_a))
	{
		initialise_nodes_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
		len--;
	}
	sort_small(stack_a, stack_b);
	while (*stack_b)
	{
		initialise_b_nodes(*stack_a, *stack_b);
		min_to_top(stack_a);
	}
	min_to_top(stack_a);
}
