/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/22 10:45:33 by sfarren          ###   ########.fr       */
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
		if (i <= median - 1)
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
		// ft_printf("Checking value: %d index: %d \n", stack->value, stack->index);
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
		if (stack->value >= lb && stack->value <= ub)
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
		if (stack->value >= lb && stack->value <= ub)
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

void	move_to_top(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *lc_node, t_stack_node *target)
{
    // int cost[2];

    while ((stack_a && *stack_a != lc_node) || *stack_b != target)
    {
        // Calculate cost of getting to top
        // if (lc_node->above_median)
        //     cost[0] = lc_node->index;
        // else
        //     cost[0] = arr_size - lc_node->index;

        // if (target->above_median)
        //     cost[1] = target->index;
        // else
        //     cost[1] = arr_size - target->index;

        // ft_printf("Cost A: %d, Cost B: %d\n", cost[0], cost[1]);

        // Determine the appropriate rotations
        if ((stack_a && *stack_a != lc_node) && *stack_b != target)
        {
            if (lc_node->above_median && target->above_median)
            {
                // ft_printf("Both nodes above median: rr\n");
                rr(stack_a, stack_b);
            }
            else if (!lc_node->above_median && !target->above_median)
            {
                // ft_printf("Both nodes below median: rrr\n");
                rrr(stack_a, stack_b);
            }
            else
            {
                if (lc_node->above_median)
                {
                    // ft_printf("lc_node above median: ra\n");
                    ra(stack_a);
                }
                else
                {
                    // ft_printf("lc_node below median: rra\n");
                    rra(stack_a);
                }

                if (target->above_median)
                {
                    // ft_printf("target above median: rb\n");
                    rb(stack_b);
                }
                else
                {
                    // ft_printf("target below median: rrb\n");
                    rrb(stack_b);
                }
            }
        }
        else if (stack_a && *stack_a != lc_node)
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

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b)
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
		// ft_printf("lb: %d\n", lb);
		ub = ((chunk + 1) * chunk_size) - 1;
		// ft_printf("ub: %d\n", ub);
		while (values_in_range(*stack_a, lb, ub))
		{
			// ft_printf("Find in range %d - %d\n", lb, ub);
			node = find_in_range(*stack_a, lb, ub);
			rev_node = rev_find_in_range(*stack_a, lb, ub);
			// ft_printf("Node: %d[%d], Rev Node: %d[%d]\n", node->value,node->index, rev_node->value, (s_size(*stack_a)-rev_node->index));
			// ft_printf("Stack a size: %d\n", s_size(*stack_a));
			if (node->index < s_size(*stack_a) - rev_node->index) // not arr size calc stack a len
				lc_node = node;
			else
				lc_node = rev_node;
			// ft_printf("LC Node: %d - index: %d\n", lc_node->value, lc_node->index);
			if (*stack_b == NULL)
			{
				// rotate lc_node-> index times to top of stack
				rotate_to_top(stack_a, NULL, lc_node, NULL);
				// push to stack b
				pb(stack_a, stack_b);
			}
			else
			{
				// ft_printf("Nodes in b\n");
				//find the target node in `b` for lc_node
				set_target(lc_node, stack_b);
				// ft_printf("LC Node: %d - index: %d\n", lc_node->value, lc_node->index);
				// ft_printf("Target: %d - index: %d\n", lc_node->target->value, lc_node->target->index);

				move_to_top(stack_a, stack_b, lc_node, lc_node->target);
				pb(stack_a, stack_b);

			}
			// ft_printf("index A\n");
			current_index(*stack_a);
			// ft_printf("index B\n");
			current_index(*stack_b);
			// ft_printf("---\n");
			// ft_printf("Stack A:\n");
			// print_stack(*stack_a);
			// ft_printf("\nStack B:\n");
			// print_stack(*stack_b);
			// ft_printf("---\n");
		}
		chunk++;
	}
	//push b to a
	//find biggest node in b
	//push to a
	// repeat until b is empty
	while (*stack_b)
	{
		// ft_printf("Pushing from b to a\n");
		// min_b = find_min(*stack_b);
		// max_b = find_max(*stack_b);
		// if (min_b->index < s_size(*stack_b) - max_b->index)
		// 	lc_node = min_b;
		// else
		// 	lc_node = max_b;
		lc_node = find_max(*stack_b);
		// ft_printf("LC Node: %d - index: %d\n", lc_node->value, lc_node->index);
		move_to_top(NULL, stack_b, NULL, lc_node);
		// ft_printf("Pushing from b to a\n");
		// ft_printf("LC Node: %d - index: %d\n", lc_node->value, lc_node->index);
		current_index(*stack_a);
		current_index(*stack_b);
		// ft_printf("---\n");
		//print_stack(*stack_a);
		//print_stack(*stack_b);
		pa(stack_a, stack_b);
	}
}

