/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/19 11:13:02 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	init_stack_a(&stack_a, argc, argv);
	ft_printf("stack len: %d\n", stack_len(stack_a));
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sort_two(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
		{
			ft_printf("Stack A - big\n");
			print_stack(stack_a);
			sort_big(&stack_a, &stack_b);
		}
	}
	 // Debug prints to check final stack states
    ft_printf("Final stack A\n");
    print_stack(stack_a);
    ft_printf("Final stack B\n");
    print_stack(stack_b);

    free_stack(stack_a);
    free_stack(stack_b);
	return (0);
}
