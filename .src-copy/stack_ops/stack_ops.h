/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:02:25 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/15 15:19:21 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

// # include "../push_swap.h"
# include "../stack.h"
# include "../libft/libft.h"

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
#endif
