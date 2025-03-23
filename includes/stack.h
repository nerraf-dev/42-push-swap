/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:18:12 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 17:46:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				lowest_cost;
	bool				above_median;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

// Stack Manipulation Functions
void	free_stack(t_stack_node **stack);
void	push_prep(t_stack_node **stack, t_stack_node *top_node,
			char stack_name);
void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
