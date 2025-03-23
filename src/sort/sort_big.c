/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 14:42:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	values_in_range(t_stack_node *stack, int *bounds)
{
	while (stack)
	{
		if (stack->value >= bounds[0] && stack->value <= bounds[1])
			return (1);
		stack = stack->next;
	}
	return (0);
}

static t_stack_node	*find_in_range(t_stack_node *stack, int *bounds)
{
	while (stack)
	{
		if (stack->value >= bounds[0] && stack->value <= bounds[1])
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static t_stack_node	*rev_find_in_range(t_stack_node *stack, int *bounds)
{
	t_stack_node	*last;

	last = NULL;
	while (stack)
	{
		if (stack->value >= bounds[0] && stack->value <= bounds[1])
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


void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b, int chunk_size, int num_chunks)
{
	int				chunk;
	int				bounds[2];
	t_stack_node	*node;
	t_stack_node	*rev_node;
	t_stack_node	*lc_node;

	chunk = 0;
	while (chunk < num_chunks)
	{
		bounds[0] = chunk * chunk_size;
		bounds[1] = ((chunk + 1) * chunk_size) - 1;
		while (values_in_range(*stack_a, &bounds[0]))
		{
			node = find_in_range(*stack_a, &bounds[0]);
			rev_node = rev_find_in_range(*stack_a, &bounds[0]);
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
			current_index(*stack_a);
			// print_stack(*stack_a, "PB- stack_a");
			current_index(*stack_b);
			// print_stack(*stack_b, "PB- stack_b");
		}
		chunk++;
	}
	// ft_printf("Stacks after chunk move to b\n");
	// print_stack(*stack_a, "stack_a");
	// print_stack(*stack_b, "stack_b");
	while (*stack_b)
	{
		lc_node = find_max(*stack_b);
		// ft_printf("lc_node: %d index: %d\n", lc_node->value, lc_node->index);
		move_to_top(NULL, stack_b, NULL, lc_node);
		current_index(*stack_a);
		current_index(*stack_b);
		pa(stack_a, stack_b);
	}
}

