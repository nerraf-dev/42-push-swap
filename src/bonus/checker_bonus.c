/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_BONUS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 19:43:29 by sfarren          ###   ########.fr       */
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
		swap(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap(b);
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(op, "pa") == 0)
		push(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		push(b, a);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0); // Invalid operation
	return (1);
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
