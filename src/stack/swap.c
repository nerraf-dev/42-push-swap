/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:36:03 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 11:12:44 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Swap the first two elements of the stack.
 *
 * @param stack Pointer to the stack to be swapped.
 */
static void	swap(t_stack_node **stack)
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
 * Swap the first two elements of stack 'a' and print "sa".
 *
 * @param a Pointer to stack 'a'.
 */
void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

/**
 * Swap the first two elements of stack 'b' and print "sb".
 *
 * @param b Pointer to stack 'b'.
 */
void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

/**
 * Swap the first two elements of both stacks 'a' and 'b' and print "ss".
 *
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
