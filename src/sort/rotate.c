/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:36:51 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 19:30:58 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "../libft/libft.h"
#include <stddef.h>



static void	rotate(t_stack_node **stack)
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
	*stack = second;
	first->next->next = NULL;
}

void	ra(t_stack_node **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
