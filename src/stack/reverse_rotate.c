/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:15 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 15:07:39 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void	reverse_rotate(t_stack_node	*stack)
// {
// 	t_stack_node	*first;
// 	t_stack_node	*second;

// 	if (!stack || !(stack)->top->next)
// 		return ;
// 	first = stack->top;
// 	while (first->next->next)
// 		first = first->next;
// 	second = first->next;
// 	first->next = NULL;
// 	second->next = stack->top;
// 	stack->top = second;
// }

void	reverse_rotate(t_stack_node	**stack)
{
	t_stack_node	*prev;
	t_stack_node	*current;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rra(t_stack_node	**stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
