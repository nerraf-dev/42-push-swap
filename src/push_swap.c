/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/14 12:37:36 by sfarren          ###   ########.fr       */
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

void	handle_error(bool error, char **split, int *int_array)
{
	if (error)
		ft_printf_fd(2, "Error: %s\n");
	if (split)
		free_split(split);
	if (int_array)
		free(int_array);
	exit(1);
}

void print_stack(t_stack_node *stack, const char *stack_name)
{
    t_stack_node *current = stack;

    ft_printf("Stack %s:\n", stack_name);
    while (current != NULL)
    {
        ft_printf("Value: %d\n", current->value);
        current = current->next;
    }
    ft_printf("\n");
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
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	if (!stack_a)
		handle_error(true, NULL, int_array);
	if (arr_size <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	free(int_array);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
