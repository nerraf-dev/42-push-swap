/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:36:03 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 13:59:36 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * swap - Swap the first two elements of the stack.
 * @stack: Pointer to the stack to be swapped.
 *
 * This function swaps the first two elements of the stack. If the stack
 * has less than two elements, the function does nothing.
 */
void	swap(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next;
	t_stack_node	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	current = *stack;
	next = current->next;
	prev = current->prev;
	(*stack) = next;
	current->prev = next;
	current->next = next->next;
	next->prev = prev;
	next->next = current;
}

/**
 * sa - Swap the first two elements of stack 'a' and print "sa".
 * @a: Pointer to stack 'a'.
 *
 * This function swaps the first two elements of stack 'a' and prints "sa".
 */
void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

/**
 * sb - Swap the first two elements of stack 'b' and print "sb".
 * @b: Pointer to stack 'b'.
 *
 * This function swaps the first two elements of stack 'b' and prints "sb".
 */
void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

/**
 * ss - Swap the first two elements of both stacks 'a' and 'b' and print "ss".
 * @a: Pointer to stack 'a'.
 * @b: Pointer to stack 'b'.
 *
 * This function swaps the first two elements of both stacks 'a' and 'b'
 * and prints "ss".
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
