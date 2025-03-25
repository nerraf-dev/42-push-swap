/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:25:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 13:58:16 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * push - Moves the top element from the source stack to the destination stack.
 * @dst: Double pointer to the destination stack.
 * @src: Double pointer to the source stack.
 *
 * This function takes the top element from the source stack and places it
 * on top of the destination stack. If the source stack is empty, the function
 * does nothing.
 */
void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

/**
 * pa - Pushes the top element from stack_b to stack_a and prints "pa".
 * @stack_a: Pointer to stack_a.
 * @stack_b: Pointer to stack_b.
 *
 * This function moves the top element from stack_b to stack_a and prints "pa".
 */
void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

/**
 * pb - Pushes the top element from stack_a to stack_b and prints "pb".
 * @stack_a: Pointer to stack_a.
 * @stack_b: Pointer to stack_b.
 *
 * This function moves the top element from stack_a to stack_b and prints "pb".
 */
void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
