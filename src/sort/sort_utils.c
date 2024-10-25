/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:34:31 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 14:34:33 by sfarren          ###   ########.fr       */
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
