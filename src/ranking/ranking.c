/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:41:29 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/25 14:06:39 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Swaps two integers.
 * @param a The first integer.
 * @param b The second integer.
 */
static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Sorts an array of integers using bubble sort.
 * @param arr The array to sort.
 * @param size The size of the array.
 */
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
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

/**
 * Assigns ranks to values in the input array.
 * @param arr The input array.
 * @param ranks The array to store ranks.
 * @param size The size of the arrays.
 */
void	assign_ranks(int *arr, int *ranks, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		handle_error(true, NULL, arr);
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
