/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/05 21:20:33 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ranking/ranking.h"
// #include "./sort/sort_ops.h"

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

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Memory Allocation Failed");
		return (NULL);
	}
	stack->top = NULL;
	return (stack);
}

void	push(t_stack *stack, int value, int rank)
{
	t_node	*new_node;

	new_node = create_node(value, rank);
	new_node->next = stack->top;
	stack->top = new_node;
}

// Function to print the stack
void	print_stack(t_stack *stack)
{
	t_node	*current;

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
	t_stack	*stack_b;
	t_node	*current;
	t_node	*temp;

	ranks = get_ranks(arr, length);
	if (!ranks)
	{
		ft_printf("Memory Allocation Failed");
		return (-1);
	}
	stack_a = create_stack();
	if (!stack_a)
	{
		free(ranks);
		return (-1);
	}
	i = length - 1;
	while (i > -1)
	{
		push(stack_a, arr[i], ranks[i]);
		i--;
	}
	// print_stack(stack_a);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a);
		free(ranks);
		return (-1);
	}
	stack_b->top = NULL;
	if (length == 2)
		sort_two(stack_a, ranks);
	else if (length == 3)
		sort_three(stack_a, ranks, 0, 2);
	else if (length <= 5)

	{
		ft_printf("SORT 4/5\n");
		//push top 1 or 2 to b
		//sort 3

	}
	else
		ft_printf("SORT BIG\n");
	// Print the stacks for checking - remove this later
	ft_printf("STACK A\n");
	print_stack(stack_a);
	ft_printf("STACK B\n");
	print_stack(stack_b);

	// Free the stack
	current = stack_a->top;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack_a);
	free(stack_b);
	free(ranks);
	return (0);
}

