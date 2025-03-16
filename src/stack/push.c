/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:25:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:35:59 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Pushes the top element from src stack to dst stack.
 *
 * @param dst The destination stack.
 * @param src The source stack.
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
 * @brief Pushes the top element from stack b to stack a and prints "pa".
 *
 * @param stack_a The destination stack a.
 * @param stack_b The source stack b.
 */
void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

/**
 * @brief Pushes the top element from stack a to stack b and prints "pb".
 *
 * @param stack_a The source stack a.
 * @param stack_b The destination stack b.
 */
void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
