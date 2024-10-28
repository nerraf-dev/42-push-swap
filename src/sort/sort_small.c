/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/28 11:13:18 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_b)
	{
		push_prep(stack_a, (*stack_b)->target, 'a');
		pa(stack_a, stack_b);
	}
}

static void	sort_two(t_stack_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

static void	sort_three(t_stack_node	**stack)
{
	t_stack_node	*current;
	int				max;

	current = *stack;
	max = get_max(current);
	if (current->value == max)
		ra(stack);
	else if (current->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	if (stack_size(*stack_a) == 2)
		sort_two(stack_a);
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else
	{
		while (stack_size(*stack_a) > 3)
			pb(stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b)
		{
			initialise_b_nodes(*stack_a, *stack_b);
			push_b_to_a(stack_a, stack_b);
		}
		current_index(*stack_a);
		min_to_top(stack_a);
	}
}
