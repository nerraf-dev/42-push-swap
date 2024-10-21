/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 15:20:03 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_max(t_stack_node *stack)
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

// static t_stack_node	*find_max(t_stack stack)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*max;

// 	current = stack.top;
// 	max = current;
// 	while (current)
// 	{
// 		if (current->value > max->value)
// 			max = current;
// 		current = current->next;
// 	}
// 	return (max);
// }

void	sort_two(t_stack_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
	}
}

void	sort_three(t_stack_node	**stack)
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
