/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:58:17 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 19:33:12 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

int				sort_two(t_stack_node **stack);
int				sort_three(t_stack_node **stack);

// Max Min
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
// Push_Swap_Commands
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			sa(t_stack_node **stack);
void			sb(t_stack_node **stack);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			ra(t_stack_node **stack);
void			rb(t_stack_node **stack);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			rra(t_stack_node **stack);
void			rrb(t_stack_node **stack);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
