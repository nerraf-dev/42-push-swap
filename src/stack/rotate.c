/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:36:51 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:35:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Rotates the stack by moving the first element to the end.
 *
 * @param stack The stack to rotate.
 */
static void	rotate(t_stack_node	**stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	while (first->next)
		first = first->next;
	first->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

/**
 * @brief Rotates stack a and prints "ra".
 *
 * @param stack The stack a to rotate.
 */
void	ra(t_stack_node	**stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

/**
 * @brief Rotates stack b and prints "rb".
 *
 * @param stack The stack b to rotate.
 */
void	rb(t_stack_node	**stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

/**
 * @brief Rotates both stacks a and b, and prints "rr".
 *
 * @param stack_a The stack a to rotate.
 * @param stack_b The stack b to rotate.
 */
void	rr(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
