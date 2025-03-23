/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 12:42:20 by sfarren          ###   ########.fr       */
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
 * @brief Handles errors by printing an error message and freeing memory.
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

// TODO: remove print_stack function before push to 42 repo
/**
 * @brief Prints the elements of a stack.
 *
 * @param stack The stack to print.
 */
void	print_stack(t_stack_node *stack, char *label )
{
	t_stack_node	*current;

	current = stack;
	if (label)
		ft_printf("Stack %s:\n", label);
	while (current)
	{
		ft_printf("value: %d - index: %d\n", current->value, current->index);
		current = current->next;
	}
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
