/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:47:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 13:15:41 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


/**
 * @brief Handles errors by printing an error message and freeing memory.
 *
 * @param error A boolean indicating if an error occurred.
 * @param split A pointer to an array of strings to be freed.
 * @param int_array A pointer to an array of integers to be freed.
 */
void	handle_error(bool error, char *msg, char **split, int *int_array)
{
	if (error)
		ft_printf_fd(2, "Error\n");
	if (split)
		free_split(split);
	if (int_array)
		free(int_array);
	exit(1);
}

// TODO: remove print_stack function before push to 42 repo
/**
 * @brief Prints the elements of a stack.
 *
 * @param stack The stack to print.
 */
void	print_stack(t_stack_node *stack, char *label )
{
	t_stack_node	*current;

	current = stack;
	if (label)
		ft_printf("Stack %s:\n", label);
	while (current)
	{
		ft_printf("value: %d - index: %d\n", current->value, current->index);
		current = current->next;
	}
}
