/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:12:43 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 21:35:31 by sfarren          ###   ########.fr       */
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
		// ft_printf("Index: %d\n", current->index);
		current = current->next;
	}
}

void	init_stack_a(t_stack_node **a, int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = parse_arguments(argc, argv);
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
	print_stack(*a);
	free(arr);
}


