/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 14:42:13 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/init.h"

// static void	check_stack_output(t_stack_node *stack_a, t_stack_node *stack_b)
// {
// 		 // Debug prints to check final stack states
// 	ft_printf("Final stack A\n");
// 	print_stack(stack_a);
// 	ft_printf("Final stack B\n");
// 	print_stack(stack_b);
// }

int	main(int argc, char **argv)
{
	t_stack_node		*stack_a;
	//t_stack_node	*stack_b;
	int			len;

	stack_a = NULL;
	// stack_b = NULL;
	if (argc == 1)
		return (1);
	initialise_stack(&stack_a, argc, argv);
	print_stack(stack_a, 'a');
	len = stack_len(stack_a);
	if (!stack_sorted(stack_a))
	{
		if (len == 2)
			sort_two(&stack_a);
		else if (len == 3)
			sort_three(&stack_a);
		// else
		// 	sort_big(&stack_a, &stack_b);
	}

	print_stack(stack_a, 'a');
	free_stack(stack_a);
	// free_stack(stack_b);
	return (0);
}
