/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:39:44 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 19:43:45 by sfarren          ###   ########.fr       */
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
	int				moves;
	t_stack_node	*stack_a;
	// t_stack_node *stack_b;

	moves = 0;
	stack_a = NULL;
	// stack_b = NULL;
	if (argc == 1 )
		return (1);
	init_stack_a(&stack_a, argc, argv);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
		{
			ft_printf("sort_two\n");
			moves = sort_two(&stack_a);
		}
		else if (stack_len(stack_a) == 3)
		{
			moves = sort_three(&stack_a);
			ft_printf("sort_three\n");
		}
		else
			ft_printf("sort_big\n");

	}
	ft_printf("MOVES: %d\n", moves);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
