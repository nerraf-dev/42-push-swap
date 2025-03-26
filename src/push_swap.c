/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/26 21:51:19 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Checks if the array is sorted in ascending order.
 *
 * @param int_array The array of integers to check.
 * @param arr_size The size of the array.
 * @return true if the array is sorted, false otherwise.
 */
static bool	is_sorted(int *int_array, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size - 1)
	{
		if (int_array[i] > int_array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief The main function that initializes the stacks and sorts the array.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int Returns 0 on success, exits with 1 on error.
 */
int	main(int argc, char **argv)
{
	int				*int_array;
	int				arr_size;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);
	if (is_sorted(int_array, arr_size))
		return (0);
	stack_a = initialise_stack(int_array, arr_size);
	stack_b = initialise_stack(NULL, 0);
	if (!stack_a)
		handle_error(true, NULL, int_array);
	if (arr_size <= 5)
		sort_small(&stack_a, &stack_b, arr_size);
	else if (arr_size <= 100)
		sort_big(&stack_a, &stack_b, 20, 5);
	else
		sort_radix(&stack_a, &stack_b, arr_size);
	free(int_array);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
