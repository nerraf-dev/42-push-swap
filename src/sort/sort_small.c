/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 21:26:13 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
	}
}

void	sort_three(t_stack_node **stack)
{
	int			max;
	// int			min;

	// min = find_min(*stack)->value;
	max = find_max(*stack)->value;
	ft_printf("Stack A: top: %d, next: %d\n", (*stack)->value, (*stack)->next->value);
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
