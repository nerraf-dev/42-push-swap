/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:36:03 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:35:23 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Swaps the first two elements of the stack.
 *
 * @param stack The stack to perform the swap on.
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
 * @brief Swaps the first two elements of stack a and prints "sa".
 *
 * @param a The stack a to perform the swap on.
 */
void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

/**
 * @brief Swaps the first two elements of stack b and prints "sb".
 *
 * @param b The stack b to perform the swap on.
 */
void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

/**
 * @brief Swaps the first two elements of both stacks a and b, and prints "ss".
 *
 * @param a The stack a to perform the swap on.
 * @param b The stack b to perform the swap on.
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
