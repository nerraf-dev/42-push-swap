/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/16 15:54:34 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*sort_two(t_stack *stack, int *arr)
{
	static char	*instructions;

	if (arr[0] == 1 && arr[1] == 0)
	{
		sa(stack);
		return (instructions = "sa\n");
	}
	return (instructions = "none required\n");
}

char	*sort_three(t_stack *stack, int *arr, int min, int max)
{
	char	*instructions;

	if (arr[0] == min && arr[1] == max)
	{
		sa(stack);
		ra(stack);
		return (instructions = "sa,ra\n");
	}
	if (arr[0] == max && arr[1] == min)
	{
		ra(stack);
		return (instructions = "ra\n");
	}
	if (arr[0] == max && arr[2] == min)
	{
		sa(stack);
		rra(stack);
		return (instructions = "sa,rra\n");
	}
	return (instructions = "");
}
