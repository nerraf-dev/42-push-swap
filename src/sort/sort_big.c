/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/21 15:36:36 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Rotate both stacks until the least cost node is at the top.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param lc_node The least cost node.
 */
// static void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
// 				t_stack_node *lc_node)
// {
// 	while (*stack_b != lc_node && *stack_a != lc_node)
// 		rr(stack_a, stack_b);
// 	current_index(*stack_a);
// 	current_index(*stack_b);
// }

/**
 * Reverse rotate both stacks until the least cost node is at the top.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param lc_node The least cost node.
 */
// static void	rev_rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
// 				t_stack_node *lc_node)
// {
// 	while (*stack_b != lc_node && *stack_a != lc_node)
// 		rrr(stack_a, stack_b);
// 	current_index(*stack_a);
// 	current_index(*stack_b);
// }

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = s_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

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
	while (*stack_a != top_node_a || (stack_b && *stack_b != top_node_b))
	{
		if (*stack_a != top_node_a && stack_b && *stack_b != top_node_b)
		{
			if (top_node_a->above_median && top_node_b && top_node_b->above_median)
				rr(stack_a, stack_b);
			else if (!top_node_a->above_median && top_node_b && !top_node_b->above_median)
				rrr(stack_a, stack_b);
			else
				break ;
		}
		else if (*stack_a != top_node_a)
		{
			if (top_node_a->above_median)
				ra(stack_a);
			else
				rra(stack_a);
		}
		else if (stack_b && *stack_b != top_node_b)
		{
			if (top_node_b && top_node_b->above_median)
				rb(stack_b);
			else if (top_node_b)
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

void	move_to_top(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *lc_node, t_stack_node *target, int arr_size)
{
	int	cost[2];

	while (*stack_a != lc_node || *stack_b != target)
	{
		// Calculate cost of getting to top
		if (lc_node->above_median)
			cost[0] = lc_node->index;
		else
			cost[0] = arr_size - lc_node->index;

		if (target->above_median)
			cost[1] = target->index;
		else
			cost[1] = arr_size - target->index;

		ft_printf("Cost A: %d, Cost B: %d\n", cost[0], cost[1]);

		// Determine the appropriate rotations
		if (*stack_a != lc_node && *stack_b != target)
		{
			if (lc_node->above_median && target->above_median)
				rr(stack_a, stack_b);
			else if (!lc_node->above_median && !target->above_median)
				rrr(stack_a, stack_b);
			else
			{
				if (lc_node->above_median)
					ra(stack_a);
				else
					rra(stack_a);

				if (target->above_median)
					rb(stack_b);
				else
					rrb(stack_b);
			}
		}
		else if (*stack_a != lc_node)
		{
			if (lc_node->above_median)
				ra(stack_a);
			else
				rra(stack_a);
		}
		else if (*stack_b != target)
		{
			if (target->above_median)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b, int arr_size)
{
	int	chunk_size;
	int	num_chunks;
	int	chunk;
	int	lb;
	int	ub;
	// int cost[2];
	t_stack_node	*node;
	t_stack_node	*rev_node;
	t_stack_node	*lc_node;
	// t_stack_node	*min_b;
	// t_stack_node	*max_b;


	chunk = 0;
	chunk_size = CHUNK_SIZE;
	num_chunks = NUM_CHUNKS;
	while (chunk < num_chunks)
	{
		lb = chunk * chunk_size;
		ft_printf("lb: %d\n", lb);
		ub = ((chunk + 1) * chunk_size) - 1;
		ft_printf("ub: %d\n", ub);
		while (values_in_range(*stack_a, lb, ub))
		{
			ft_printf("Find in range\n");
			node = find_in_range(*stack_a, lb, ub);
			rev_node = rev_find_in_range(*stack_a, lb, ub);
			ft_printf("Node: %d, Rev Node: %d\n", node->value, rev_node->value);
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
				ft_printf("Nodes in b\n");
				//find the target node in `b` for lc_node
				set_target(lc_node, stack_b);
				ft_printf("LC Node: %d - index: %d\n", lc_node->value, lc_node->index);
				ft_printf("Target: %d - index: %d\n", lc_node->target->value, lc_node->target->index);
				// calc cost of getting to top
				//		if above median: cost = index
				//		if below median: cost = len - index
				// Calculate cost of getting to top
				// if (lc_node->above_median)
				// 	cost[0] = lc_node->index;
				// else
				// 	cost[0] = arr_size - lc_node->index;
				// if (lc_node->target->above_median)
				// 	cost[1] = lc_node->target->index;
				// else
				// 	cost[1] = arr_size - lc_node->target->index;
				// ft_printf("Cost A: %d, Cost B: %d\n", cost[0], cost[1]);
				move_to_top(stack_a, stack_b, lc_node, lc_node->target, arr_size);
				pb(stack_a, stack_b);
				// if lc_node is above median and target is below median
				//		rotate lc_node to top of `a`
				//		reverse rotate target to top of `b`
				// if lc_node is below median and target is above median
				//		reverse rotate lc_node to top of `a`
				//		rotate target to top of `b`
				// if lc_node is above median and target is at the top of `b`
				//		rotate lc_node to top of `a`
				// if lc_node is below median and target is at the top of `b`
				//		reverse rotate lc_node to top of `a`
				// if lc_node is at the top of `a` and target is above median
				//		rotate target to top of `b`
				// if lc_node is at the top of `a` and target is below median
				//		reverse rotate target to top of `b`
				// if lc_node is at the top of `a` and target is at the top of `b`
				//		push to `b`







			}
			ft_printf("Stack A:\n");
			print_stack(*stack_a);
			ft_printf("Stack B:\n");
			print_stack(*stack_b);
			ft_printf("index A\n");
			current_index(*stack_a);
			ft_printf("index B\n");
			current_index(*stack_b);

		}
		chunk++;
	}
}

