/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:09:55 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/14 13:44:26 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
// pb (push b): Take first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
	// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
	// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// The last element becomes the first one.
// rrr : rra and rrb at the same time.



void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack->top || !stack->top->next)
		return ;
	prev = NULL;
	current = stack->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
}



