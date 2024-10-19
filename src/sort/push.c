/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:49:24 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/19 11:29:43 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node	*temp;

    if (!*stack_b)
        return ;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    if (*stack_a)
        (*stack_a)->prev = temp;
    temp->next = *stack_a;
    temp->prev = NULL;
    *stack_a = temp;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
    // Debug prints to trace the state before the operation
    ft_printf("Before pa:\n");
    ft_printf("Stack A:\n");
    print_stack(*stack_a);
    ft_printf("Stack B:\n");
    print_stack(*stack_b);

    push(stack_a, stack_b);
    ft_printf("pa\n");

    // Debug prints to trace the state after the operation
    ft_printf("After pa:\n");
    ft_printf("Stack A:\n");
    print_stack(*stack_a);
    ft_printf("Stack B:\n");
    print_stack(*stack_b);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
    // Debug prints to trace the state before the operation
    ft_printf("Before pb:\n");
    ft_printf("Stack A:\n");
    print_stack(*stack_a);
    ft_printf("Stack B:\n");
    print_stack(*stack_b);

    push(stack_b, stack_a);
    ft_printf("pb\n");

    // Debug prints to trace the state after the operation
    ft_printf("After pb:\n");
    ft_printf("Stack A:\n");
    print_stack(*stack_a);
    ft_printf("Stack B:\n");
    print_stack(*stack_b);
}
