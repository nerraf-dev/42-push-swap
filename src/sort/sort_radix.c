/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:02:04 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/14 20:30:35 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
