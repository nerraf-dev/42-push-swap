/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:25:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 11:10:10 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Pushes the top element from the source stack to the destination stack.
 *
 * @param dst Pointer to the destination stack.
 * @param src Pointer to the source stack.
 */
static void	push(t_stack_node **dst, t_stack_node **src)
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
 * @brief Pushes the top element from stack_b to stack_a and prints "pa".
 *
 * @param stack_a Pointer to stack_a.
 * @param stack_b Pointer to stack_b.
 */
void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

/**
 * @brief Pushes the top element from stack_a to stack_b and prints "pb".
 *
 * @param stack_a Pointer to stack_a.
 * @param stack_b Pointer to stack_b.
 */
void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
