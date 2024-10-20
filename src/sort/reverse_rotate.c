/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:04:15 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/19 19:12:55 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *second_last;

    // Check if the stack is empty or has only one element
    if (!stack || !*stack || !(*stack)->next)
        return;

    // Find the last and second-to-last nodes
    last = get_last_node(*stack);
    second_last = last->prev;

    // Debugging statements
    ft_printf("Before reverse_rotate: last = %d, second_last = %d\n", last->value, second_last ? second_last->value : -1);

    // Detach the last node from the stack
    if (second_last)
        second_last->next = NULL;

    // Update the last node's pointers
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;

    // Update the stack pointer to point to the new top
    *stack = last;

    // Debugging statements
    ft_printf("After reverse_rotate: new top = %d\n", (*stack)->value);

    // Print the entire stack for debugging
    t_stack_node *current = *stack;
    ft_printf("Stack state after reverse_rotate: ");
    while (current)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}

void	rra(t_stack_node **stack)
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
