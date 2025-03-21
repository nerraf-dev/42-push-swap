/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:26:32 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/21 11:03:53 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	values_in_range(t_stack_node *stack, int lb, int ub)
{
	while (stack)
	{
		if (stack->value >= lb && stack->value < ub)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static t_stack_node	*find_in_range(t_stack_node *stack, int lb, int ub)
{
	while (stack)
	{
		if (stack->value >= lb && stack->value < ub)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static t_stack_node	*rev_find_in_range(t_stack_node *stack, int lb, int ub)
{
	t_stack_node	*last;

	last = NULL;
	while (stack)
	{
		if (stack->value >= lb && stack->value < ub)
			last = stack;
		stack = stack->next;
	}
	return (last);
}

void	rotate_to_top(t_stack_node **stack_a, t_stack_node **stack_b,
	t_stack_node *top_node_a, t_stack_node *top_node_b)
{
	while (*stack_a != top_node_a || *stack_b != top_node_b)
	{
		if (*stack_a != top_node_a && *stack_b != top_node_b)
		{
			if (top_node_a->above_median && top_node_b->above_median)
				rr(stack_a, stack_b);
			else if (!top_node_a->above_median && !top_node_b->above_median)
				rrr(stack_a, stack_b);
			else
				break;
		}
		else if (*stack_a != top_node_a)
		{
			if (top_node_a->above_median)
				ra(stack_a);
			else
				rra(stack_a);
		}
		else if (*stack_b != top_node_b)
		{
			if (top_node_b->above_median)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	set_target(t_stack_node *node, t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*target;
	t_stack_node	*min;
	t_stack_node	*max;
	if (!node || !stack || !*stack)
		return ;
	min = find_min(*stack);
	max = find_max(*stack);
	if (node->value > max->value)
		target = min;
	else if (node->value < min->value)
		target = max;
	else
	{
		current = *stack;
		target = NULL;
		while (current)
		{
			if (current->value < node->value)
			{
				if (!target || current->value > target->value)
					target = current;
			}
			current = current->next;
		}
		if (!target)
			target = min;
	}
	node->target = target;
}

void	sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b, int arr_size)
{
	int	chunk_size;
	int	num_chunks;
	int	chunk;
	int	lb;
	int	ub;
	t_stack_node	*node;
	t_stack_node	*rev_node;
	t_stack_node	*lc_node;
	t_stack_node	*min_b;
	t_stack_node	*max_b;


	chunk = 0;
	chunk_size = CHUNK_SIZE;
	num_chunks = NUM_CHUNKS;
	while (chunk < num_chunks)
	{
		lb = chunk * chunk_size;
		ub = ((chunk + 1) * chunk_size) - 1;
		while (values_in_range(*stack_a, lb, ub))
		{
			node = find_in_range(*stack_a, lb, ub);
			rev_node = rev_find_in_range(*stack_a, lb, ub);
			if (node->index < arr_size - rev_node->index)
				lc_node = node;
			else
				lc_node = rev_node;
			if (*stack_b == NULL)
			{
				// rotate lc_node-> index times to top of stack
				rotate_to_top(stack_a, NULL, lc_node, NULL);
				// push to stack b
				pb(stack_a, stack_b);
			}
			else
			{
				//find the target node in `b` for lc_node
				set_target(lc_node, stack_b);


			}

			// get cost of movement to move target to top of 'b'
			//

			// if stack b has nodes, check if lc_node value will be largest or smallest in `b`
			//		if value will be largest then get `b` smallest value to top
			//		if value will be smallest, get `b` largest to top
			// otherwise just push (or maybe it should push on to a smaller number)
			//once we know where to push, we can rotate to top
			// Checks should be made to see if roating both stascks (rr, rrr) is possible to save moves
			// then just roate stack by stack once all dual rotations are exhasted



			rotate_to_top(stack_a, stack_b, lc_node, lc_node->target);
			current_index(*stack_a);
			current_index(*stack_b);

		}
		chunk++;
	}
}
