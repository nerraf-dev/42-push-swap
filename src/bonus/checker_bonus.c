/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/31 11:04:04 by sfarren          ###   ########.fr       */
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

static void	free_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

static void	process_operations(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!execute_operation(line, stack_a, stack_b))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

static void	print_result(t_stack_node *stack_a, t_stack_node *stack_b)
{
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	int				*int_array;
	int				arr_size;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	arr_size = 0;
	if (argc < 2)
		return (0);
	int_array = argument_parser(argc, argv, &arr_size);
	stack_a = initialise_stack(int_array, arr_size);
	stack_b = initialise_stack(NULL, 0);
	free(int_array);
	if (!stack_a)
		return (ft_printf_fd(2, "Error\n"), 1);
	process_operations(&stack_a, &stack_b);
	print_result(stack_a, stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
