/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/26 15:17:47 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
// TODO: delete this function
void print_stack(t_stack_node *head, char *name)
{
	t_stack_node *current = head;

	ft_printf("Stack %s:\n", name);
	while (current != NULL)
	{
		ft_printf("Value: %d\n", current->value);
		ft_printf("Index: %d\n", current->index);
		ft_printf("Cost: %d\n", current->cost);
		ft_printf("Lowest Cost: %d\n", current->lowest_cost);
		ft_printf("Above Median: %d\n", current->above_median);
		ft_printf("\n");
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
	t_stack_node	*stack_b;

	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);
	if (is_sorted(int_array, arr_size))
		return (0);
	stack_a = initialise_stack(int_array, arr_size);
	stack_b = initialise_stack(NULL, 0);
	if(!stack_a)
		handle_error("Memory allocation failed", NULL, int_array);
	if (arr_size <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);

	
	// free(int_array);
	free(int_array);
	free_stack(&stack_a);
	free_stack(&stack_b);
	// END OF MAIN
	return (0);
}
