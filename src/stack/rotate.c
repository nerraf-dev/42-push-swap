/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:36:51 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 14:01:21 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * rotate - Rotate the stack by moving the first element to the end.
 * @stack: Pointer to the stack to be rotated.
 *
 * This function moves the first element of the stack to the end of the stack.
 * If the stack has less than two elements, the function does nothing.
 */
void	rotate(t_stack_node	**stack)
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
 * ra - Rotate stack 'a' and print "ra".
 * @stack: Pointer to stack 'a'.
 *
 * This function rotates stack 'a' by moving the first element to the end
 * and prints "ra".
 */
void	ra(t_stack_node	**stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

/**
 * rb - Rotate stack 'b' and print "rb".
 * @stack: Pointer to stack 'b'.
 *
 * This function rotates stack 'b' by moving the first element to the end
 * and prints "rb".
 */
void	rb(t_stack_node	**stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

/**
 * rr - Rotate both stacks 'a' and 'b' and print "rr".
 * @stack_a: Pointer to stack 'a'.
 * @stack_b: Pointer to stack 'b'.
 *
 * This function rotates both stacks 'a' and 'b' by moving the first element
 * of each stack to the end and prints "rr".
 */
void	rr(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
