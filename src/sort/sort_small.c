/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 20:06:46 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "sort.h"
#include "../libft/libft.h"

int	sort_two(t_stack_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
		return (1);
	}
	return (0);
}

int	sort_three(t_stack_node **stack)
{
	int			min;
	int			max;

	min = find_min(*stack)->value;
	max = find_max(*stack)->value;

	ft_printf("MIN: %d, MAX: %d\n", min, max);
	ft_printf("Stack A: top: %d, next: %d\n", (*stack)->value, (*stack)->next->value);
	
	if ((*stack)->value == max && (*stack)->next->value == min)
	{
		ra(stack);
		return (1);
	}
	else if ((*stack)->value == min && (*stack)->next->value == max)
	{
		sa(stack);
		ra(stack);
		return (2);
	}
	else if ((*stack)->value == min)
		sa(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	else if ((*stack)->value == max && (*stack)->next->value == min)
		ra(stack);
	else
	{
		sa(stack);
		ra(stack);
		return (2);
	}
	return (0);
}
