/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:39:44 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 13:55:14 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_error_and_exit(const char *message, int *arr)
// {
// 	ft_printf("%s\n", message);
// 	if (arr)
// 		free(arr);
// 	exit(1);
// }



int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	// t_stack_node *stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_stack_a(&stack_a, argc, argv);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			ft_printf("sa\n");
		else if (stack_len(stack_a) == 3)
			ft_printf("sort_three\n");
		else
			ft_printf("sort_big\n");

	}
	free_stack(stack_a);
	return (0);
}
