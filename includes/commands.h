/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:49:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 14:07:02 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "stack.h"

// Push_Swap Commands
void			push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			swap(t_stack_node **stack);
void			sa(t_stack_node **stack);
void			sb(t_stack_node **stack);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			rotate(t_stack_node	**stack);
void			ra(t_stack_node **stack);
void			rb(t_stack_node **stack);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate(t_stack_node	**stack);
void			rra(t_stack_node **stack);
void			rrb(t_stack_node **stack);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);

void			rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *lc_node);
void			rev_rotate_stacks(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *lc_node);
#endif
