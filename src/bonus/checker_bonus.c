/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_BONUS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 13:29:58 by sfarren          ###   ########.fr       */
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
	else if (ft_strcmp(op, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "ra") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(a, b);
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
		handle_error(true, NULL, int_array);
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
			free_stack(&stack_a);
			free_stack(&stack_b);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	// print_stack(stack_a, "a");
	// print_stack(stack_b, "b");
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
