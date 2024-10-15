/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:49:24 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/15 15:20:24 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "../libft/libft.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*top;

	if (!src->top)
		return ;
	top = src->top;
	src->top = src->top->next;
	top->next = dst->top;
	dst->top = top;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pb\n");
}
