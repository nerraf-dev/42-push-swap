/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:20:12 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/18 14:20:04 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
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

static void	set_target_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			target_index;

	while (stack_a)
	{
		target_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->index > target_index)
			{
				target_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b ->next;
		}
		if (target_index == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

static void	calculate_cost_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	set_lowest_cost(t_stack_node *stack)
{
	long			lowest_cost;
	t_stack_node	*lowest_cost_node;

	if (!stack)
		return ;
	lowest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < lowest_cost)
		{
			lowest_cost = stack->cost;
			lowest_cost_node = stack;
		}
		stack = stack->next;
	}
	lowest_cost_node->lowest_cost = true;
}

void	initialise_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	calculate_cost_a(stack_a, stack_b);
	set_lowest_cost(stack_a);
}
