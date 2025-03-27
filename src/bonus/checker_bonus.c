/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/27 13:54:37 by sfarren          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int				*int_array;
	int				arr_size;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*line;

	if (argc < 2)
		return (0);
	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);
	stack_a = initialise_stack(int_array, arr_size);
	stack_b = initialise_stack(NULL, 0);
	free(int_array);
	if (!stack_a)
		ft_printf_fd(2, "Error\n");
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!execute_operation(line, &stack_a, &stack_b))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
