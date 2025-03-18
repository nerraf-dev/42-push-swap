/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:36:51 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 11:12:36 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Rotate the stack by moving the first element to the end.
 *
 * @param stack Pointer to the stack to be rotated.
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
 * Rotate stack 'a' and print "ra".
 *
 * @param stack Pointer to stack 'a'.
 */
void	ra(t_stack_node	**stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

/**
 * Rotate stack 'b' and print "rb".
 *
 * @param stack Pointer to stack 'b'.
 */
void	rb(t_stack_node	**stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

/**
 * Rotate both stacks 'a' and 'b' and print "rr".
 *
 * @param stack_a Pointer to stack 'a'.
 * @param stack_b Pointer to stack 'b'.
 */
void	rr(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
