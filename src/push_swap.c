/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 12:49:52 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	stack_sorted(t_stack_node	*stack)
{
	t_stack_node	*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_sorted(int *int_array, int arr_size)
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

void print_stack(t_stack_node *head, char *name)
{
	t_stack_node *current = head;

	ft_printf("Stack %s:\n", name);
	while (current != NULL)
	{
		ft_printf("Value: %d\n", current->value);
		current = current->next;
	}
}

void	handle_error(const char *message, char **split, int *int_array)
{
	ft_printf("Error: %s\n", message);
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

int	main(int argc, char **argv)
{
	int				*int_array;
	int				arr_size;
	t_stack_node	*stack_a;
	// t_stack_node	*stack_b;

	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);
	// Check if array is sorted
	//  If sorted -> end
	if (is_sorted(int_array, arr_size))
		return (0);
	// If not sorted:
	//  initialise stack_a
	stack_a = initialise_stack(int_array, arr_size);
	if(!stack_a)
		handle_error("Memory allocation failed", NULL, int_array);
	print_stack(stack_a, "a");
	// populate stack_a
	// if arr_size 3 or less - sort small
	// else:
	//		initialise stack_b
	//		sort big
	// free stack_a
	// free stack_b
	// free int_array


	// free(int_array);
	free(int_array);
	// END OF MAIN
	return (0);
}
