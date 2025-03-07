/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:34:31 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/07 12:46:02 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max(t_stack_node *stack)
{
	t_stack_node	*current;
	int				max;

	current = stack;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

bool	stack_sorted(t_stack_node	*stack)
{
	t_stack_node	*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	min_to_top(t_stack_node **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
	t_stack_node *lc_node)
{
while (*stack_b != lc_node && *stack_a != lc_node)
rr(stack_a, stack_b);
current_index(*stack_a);
current_index(*stack_b);
}

void	rev_rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
	t_stack_node *lc_node)
{
while (*stack_b != lc_node && *stack_a != lc_node)
rrr(stack_a, stack_b);
current_index(*stack_a);
current_index(*stack_b);
}
