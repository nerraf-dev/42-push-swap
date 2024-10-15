/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:37:56 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/15 15:21:19 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "../libft/libft.h"

static void	reverse_rotate(t_stack *stack)
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

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rra\n");
	ft_printf("rrb\n");
}
