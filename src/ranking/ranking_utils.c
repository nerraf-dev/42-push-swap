/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:48:50 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/09 17:29:54 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ranking.h"

t_count_node	*create_count_node(int value)
{
	t_count_node	*new_node;

	new_node = (t_count_node *)malloc(sizeof(t_count_node));
	new_node->value = value;
	new_node->count = 0;
	new_node->next = NULL;
	return (new_node);
}

// Function to create a linked list for counts
t_count_node	*create_linked_list(int length)
{
	t_count_node	*head;
	t_count_node	*current;
	int		i;

	head = create_count_node(0);
	current = head;
	i = 1;
	while (i < length)
	{
		current->next = create_count_node(i);
		current = current->next;
		i++;
	}
	return (head);
}

// Function to populate the linked list with counts
void	populate_count_list(int *arr, int length, t_count_node *head, int offset)
{
	int				i;
	int				index;
	t_count_node	*current;

	i = 0;
	while (i < length)
	{
		current = head;
		index = arr[i] + offset;
		while (index > 0)
		{
			current = current->next;
			index--;
		}
		current->count++;
		i++;
	}
}

void	free_list(t_count_node *count)
{
	t_count_node	*temp;

	while (count != NULL)
	{
		temp = count;
		count = count->next;
		free(temp);
	}
}

int	bin_int(int n)
{
	int	i;
	int	rem;
	int	bin;
	// int	dec;

	bin = 0;
	i = 1;
	while (n != 0)
	{
		rem = n % 2;
		n = n / 2;
		bin = bin + (i * rem);
		i = i * 10;
	}
	return (bin);
}
