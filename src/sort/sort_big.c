/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:04:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/18 14:37:07 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_both(t_stack_node **stack_a,
						t_stack_node **stack_b,
						t_stack_node *lowest_cost_node)
{
	while (*stack_b != lowest_cost_node->target
		&& *stack_a != lowest_cost_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate_both(t_stack_node **stack_a,
								t_stack_node **stack_b,
								t_stack_node *lowest_cost_node)
{
	while (*stack_b != lowest_cost_node->target
		&& *stack_a != lowest_cost_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*low_cost_node;

	low_cost_node = find_lowest_cost(*stack_a);
	if (low_cost_node->above_median && low_cost_node->target->above_median)
		rotate_stacks(stack_a, stack_b, low_cost_node);
	else if (!(low_cost_node->above_median)
		&& !(low_cost_node->target->above_median))
		reverse_rotate_stacks(stack_a, stack_b, low_cost_node);
	set_push(stack_a, low_cost_node, 'a');
	set_push(stack_b, low_cost_node->target, 'b');
	pb(stack_a, stack_b);
}

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3)
		pb(stack_a, stack_b);
	if (len_a-- > 3)
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		initialise_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		initialise_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_to_top(stack_a);
}
