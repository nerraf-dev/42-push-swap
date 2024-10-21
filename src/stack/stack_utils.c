/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:17:16 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 15:01:14 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	if (!stack)
		return ;
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		ft_printf("Memory allocation failed");
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = get_last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	free_stack(t_stack_node	**stack)
{
	t_stack_node	*current;
	t_stack_node	*next;
	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*current;

	len = 0;
	current = stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	print_stack(t_stack_node *stack, char stack_name)
{
	t_stack_node	*current;

	current = stack;
	ft_printf("Stack %c\n", stack_name);
	while (current != NULL)
	{
		ft_printf("Value: %d\n", current->value);
		current = current->next;
	}
}
