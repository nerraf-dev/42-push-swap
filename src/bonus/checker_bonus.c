/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_BONUS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 11:16:54 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (false);

	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	execute_operation(char *op, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(a, b);
	// ... implement all other operations similarly
	else
		return (0); // Invalid operation
	return (1);
}

int	main(int argc, char **argv)
{
	int             *int_array;
	int             arr_size;
	t_stack_node    *stack_a;
	t_stack_node    *stack_b;
	char            *line;

	if (argc < 2)
		return (0); // No arguments - exit silently

	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);
	stack_a = initialise_stack(int_array, arr_size);
	stack_b = initialise_stack(NULL, 0);
	free(int_array); // Free the array after stack is created

	if (!stack_a)
		handle_error(true, NULL, NULL);

	// Read instructions from stdin line by line
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line) // EOF reached
			break;

		// Remove newline character if present
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';

		if (!execute_operation(line, &stack_a, &stack_b))
		{
			free(line);
			handle_error(false, &stack_a, &stack_b); // Invalid operation
		}
		free(line);
	}

	// After all instructions, check if stack is sorted
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
