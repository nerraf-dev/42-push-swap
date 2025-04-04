/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 14:01:25 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * reverse_rotate - Moves the last element of the stack to the top.
 * @stack: Double pointer to the head of the stack.
 *
 * This function moves the last element of the stack to the top of the stack.
 * If the stack has less than two elements, the function does nothing.
 */
void	reverse_rotate(t_stack_node	**stack)
{
	t_stack_node	*prev;
	t_stack_node	*current;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

/**
 * rra - Applies reverse_rotate to stack A and prints "rra".
 * @stack: Double pointer to the head of stack A.
 *
 * This function applies reverse_rotate to stack A and prints "rra".
 */
void	rra(t_stack_node	**stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

/**
 * rrb - Applies reverse_rotate to stack B and prints "rrb".
 * @stack: Double pointer to the head of stack B.
 *
 * This function applies reverse_rotate to stack B and prints "rrb".
 */
void	rrb(t_stack_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

/**
 * rrr - Applies reverse_rotate to both stack A and stack B, then prints "rrr".
 * @stack_a: Double pointer to the head of stack A.
 * @stack_b: Double pointer to the head of stack B.
 *
 * This function applies reverse_rotate to both stack A and stack B, then
 * prints "rrr".
 */
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
