/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/13 13:04:40 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"\


static int	stack_size(t_stack_node *stack)
{
	int				size;
	t_stack_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

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
	int		max_num;
	int		max_bits;
	int		i;
	int		j;

	len = stack_size(*stack_a);
	max_num = len - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if ((((*stack_a)->rank >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
