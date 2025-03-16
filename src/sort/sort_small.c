/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:44:03 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Push the top element from stack b to stack a.
 *
 * @param stack_a The destination stack a.
 * @param stack_b The source stack b.
 */
void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_b)
	{
		push_prep(stack_a, (*stack_b)->target, 'a');
		pa(stack_a, stack_b);
	}
}

/**
 * @brief Sort a stack of two elements.
 *
 * @param stack The stack to sort.
 */
static void	sort_two(t_stack_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

/**
 * @brief Sort a stack of three elements.
 *
 * @param stack The stack to sort.
 */
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

/**
 * @brief Sort a small stack (up to three elements).
 *
 * @param stack_a The stack to sort.
 * @param stack_b The auxiliary stack.
 * @param len The length of the stack.
 */
void	sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b, int len)
{
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else
	{
		while (len > 3)
		{
			pb(stack_a, stack_b);
			len--;
		}
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
