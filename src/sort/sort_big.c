/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/04 09:54:44 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
// 				t_stack_node *lc_node)
// {
// 	while (*stack_b != lc_node && *stack_a != lc_node)
// 		rr(stack_a, stack_b);
// 	current_index(*stack_a);
// 	current_index(*stack_b);
// }

// static void	rev_rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
// 				t_stack_node *lc_node)
// {
// 	while (*stack_b != lc_node && *stack_a != lc_node)
// 		rrr(stack_a, stack_b);
// 	current_index(*stack_a);
// 	current_index(*stack_b);
// }

// static void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	t_stack_node	*lc_node;

// 	lc_node = get_lc_node(*stack_a);
// 	if (lc_node->above_median && lc_node->target->above_median)
// 		rotate_stacks(stack_a, stack_b, lc_node);
// 	else if (!(lc_node->above_median) && !(lc_node->target->above_median))
// 		rev_rotate_stacks(stack_a, stack_b, lc_node);
// 	push_prep(stack_a, lc_node, 'a');
// 	push_prep(stack_b, lc_node->target, 'b');
// 	pb(stack_a, stack_b);
// }

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int		len;
	int		chunk_size;
	int		i;

	len = s_size(*stack_a);
	chunk_size = len / 10;
	while (len > 3)
	{
		i = 0;
		while (i < chunk_size && len > 3)
		{
			pb(stack_a, stack_b);
			len--;
			i++;
		}
		if (s_size(*stack_b) > 1 && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
	sort_small(stack_a, stack_b);
	while (*stack_b)
	{
		initialise_b_nodes(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	min_to_top(stack_a);
}
