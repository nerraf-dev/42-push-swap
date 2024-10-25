/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 13:46:37 by sfarren          ###   ########.fr       */
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

static int	stack_size(t_stack_node *stack)
{
	t_stack_node	*current;
	int				size;

	current = stack;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

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

void	sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b)
{

	if (stack_size(*stack_a) == 2)
		sort_two(stack_a);
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else
		// for 4 or 5 elements push top 1 or 2 elements to stack b
		// sort the remaining 3 elements in stack a (sort_three)
		// push the 1 or 2 elements back to stack a in correct place

		//init stack b as empty stack
		// push from stack a to stack b until stack a has 3 elements

		while (stack_size(*stack_a) > 3)
		{
			pb(stack_a, stack_b);
		}
		print_stack(*stack_b, "b");
		//free stacks



}
