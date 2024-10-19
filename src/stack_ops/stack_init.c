/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:12:43 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/19 11:03:18 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("Value: %d\n", current->value);
		current = current->next;
	}
}

void	set_push(t_stack_node **stack,
					t_stack_node *top,
					char which_stack)
{
	while (*stack != top)
	{
		if (which_stack == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (which_stack == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}

}

void	init_stack_a(t_stack_node **a, int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = parse_arguments(argc, argv);
	i = 0;
	//output array to check
	while (i < argc - 1)
	{
		ft_printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
	if (check_duplicates(arr, argc - 1))
	{
		ft_printf("Error: Duplicate number");
		free(arr);
		return ;
	}
	i = 0;
	while (i < argc - 1)
	{
		append_node(a, arr[i]);
		i++;
	}
	free(arr);
}

t_stack_node	*find_lowest_cost(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cost)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
