/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:41:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/14 12:05:40 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Swap two integers
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Bubble sort to sort the array
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

// Assign ranks to values in the input array
void	assign_ranks(int *arr, int *ranks, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		handle_error("Memory allocation failed", NULL, arr);
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	bubble_sort(sorted, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (arr[i] != sorted[j])
			j++;
		ranks[i] = j;
		i++;
	}
	free(sorted);
}
