/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/14 14:42:14 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ranking/c_sort.h"

t_node	*create_node(int value, int rank)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_printf("Memory Allocation Failed");
		return (NULL);
	}
	new_node->value = value;
	new_node->rank = rank;
	new_node->next = NULL;
	return (new_node);
}

void	push(t_stack *stack, int value, int rank)
{
	t_node	*new_node;

	new_node = create_node(value, rank);
	new_node->next = stack->top;
	stack->top = new_node;
}

// Function to print the stack
void print_stack(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	while (current != NULL)
	{
		ft_printf("Value: %d, Rank: %d\n", current->value, current->rank);
		current = current->next;
	}
}

int	push_swap(int *arr, int length)
{
	int		*ranks;
	int		i;
	t_stack	*stack_a;
	// t_node	*stack_b;
	t_node	*current;
	t_node	*temp;

	ranks = get_ranks(arr, length);
	if (!ranks)
		return (-1);

	// Print ranks
	i = 0;
	while (i < length)
	{
		ft_printf("arr: %d - rank[%d] = %d\n",arr[i], i, ranks[i]);
		i++;
	}
	 // Create stack a
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a) {
		free(ranks);
		return (-1);
	}
	stack_a->top = NULL;
	i = length - 1;
	while (i > -1)
	{
		push(stack_a, arr[i], ranks[i]);
		i--;
	}
	print_stack(stack_a);
	// Free the stack
	current = stack_a->top;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack_a);
	free(ranks);
	return (0);
}

