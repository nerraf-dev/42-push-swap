/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:02:04 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 11:16:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sort the stack using the radix sort algorithm.
 * @param stack_a The main stack to sort.
 * @param stack_b The auxiliary stack.
 * @param len The number of elements in the stack.
 */
void	sort_radix(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	int		max_num;
	int		max_bits;
	int		i;
	int		j;

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
			if ((((*stack_a)->value >> i) & 1) == 1)
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
