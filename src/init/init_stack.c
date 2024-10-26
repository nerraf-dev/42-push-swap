/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 19:30:31 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*initialise_stack(int *arr, int size)
{
	t_stack_node	*head;
	t_stack_node	*new_node;
	int				i;

	head = NULL;
	new_node = NULL;
	if (arr == NULL)
		return (head);
	i = size - 1;
	while (i >= 0)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (!new_node)
			return (NULL);
		new_node->value = arr[i];
		new_node->index = 0;
		new_node->next = head;
		new_node->prev = NULL;
		new_node->target = NULL;
		if (head != NULL)
			head->prev = new_node;
		head = new_node;
		i--;
	}
	return (head);
}

t_stack_node	*get_cost(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_prep(t_stack_node **stack,	t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
