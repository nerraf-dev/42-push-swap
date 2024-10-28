/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:36:03 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/28 11:18:15 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
