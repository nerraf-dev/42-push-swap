/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:35:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Reverses the rotation of the stack by moving the last element to the front.
 *
 * @param stack The stack to reverse rotate.
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
 * @brief Reverses the rotation of stack a and prints "rra".
 *
 * @param stack The stack a to reverse rotate.
 */
void	rra(t_stack_node	**stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

/**
 * @brief Reverses the rotation of stack b and prints "rrb".
 *
 * @param stack The stack b to reverse rotate.
 */
void	rrb(t_stack_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

/**
 * @brief Reverses the rotation of both stacks a and b, and prints "rrr".
 *
 * @param stack_a The stack a to reverse rotate.
 * @param stack_b The stack b to reverse rotate.
 */
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
