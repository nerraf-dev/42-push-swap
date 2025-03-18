/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 11:08:51 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Checks if the array is sorted in ascending order.
 *
 * This function iterates through the array and checks if each element
 * is less than or equal to the next element. If any element is found
 * to be greater than the next element, the function returns false.
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
 * @brief Handles errors by printing an error message and freeing memory.
 *
 * This function prints an error message to the standard error output
 * if the error parameter is true. It also frees the memory allocated
 * for the split array and the int_array if they are not NULL.
 *
 * @param error A boolean indicating if an error occurred.
 * @param split A pointer to an array of strings to be freed.
 * @param int_array A pointer to an array of integers to be freed.
 */
void	handle_error(bool error, char **split, int *int_array)
{
	if (error)
		ft_printf_fd(2, "Error\n");
	if (split)
		free_split(split);
	if (int_array)
		free(int_array);
	exit(1);
}

/**
 * @brief The main function that initializes the stacks and sorts the array.
 *
 * This function parses the command-line arguments to create an array of
 * integers. It then checks if the array is already sorted. If not, it
 * initializes two stacks and sorts the array using different algorithms
 * based on the size of the array. Finally, it frees the allocated memory.
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
		sort_big(&stack_a, &stack_b, arr_size);
	else
		sort_radix(&stack_a, &stack_b, arr_size);
	free(int_array);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
