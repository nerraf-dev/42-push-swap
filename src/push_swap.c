/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/13 19:07:35 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
 * @brief Handles errors by printing an error message, freeing allocated memory, and exiting the program.
 *
 * This function prints the provided error message, frees the memory allocated for the split array and the integer array,
 * and then terminates the program with an exit status of 1.
 *
 * @param message The error message to be printed.
 * @param split A pointer to an array of strings that needs to be freed. Can be NULL.
 * @param int_array A pointer to an array of integers that needs to be freed. Can be NULL.
 */
void	handle_error(bool error, char **split, int *int_array)
{
	if (error)
	 	ft_printf_fd(2, "Error\n");
	if (split)
	{
		free_split(split);
	}
	if (int_array)
	{
		free(int_array);
	}
	exit(1);
}

static void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("Value: %d, Rank: %d\n", current->value, current->rank);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int				*int_array;
	int				arr_size;
	int				*ranks;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	ft_printf("INT_MAX: %d\n", INT_MAX);
	ft_printf("INT_MIN: %d\n", INT_MIN);
	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);
	if (is_sorted(int_array, arr_size))
		return (0);
	ft_printf("arr_size: %d\n", arr_size);
	if (arr_size <= 3)
	{
		ft_printf("Sort small");
		sort_small(int_array, arr_size);
	}
	else
	{
		ranks = get_ranks(int_array, arr_size);
		stack_a = initialise_stack(int_array, ranks, arr_size);
		stack_b = initialise_stack(NULL, NULL, 0);
		if (!stack_a)
			handle_error(true, NULL, int_array);
		sort_big(&stack_a, &stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
		free(int_array);
		free(ranks);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
