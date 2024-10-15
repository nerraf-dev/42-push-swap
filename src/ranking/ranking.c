/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:18:12 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/14 14:43:59 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_sort.h"

t_count_props	get_props(int *arr, int length)
{
	int				i;
	t_count_props	props;

	i = 0;
	props.min = INT_MAX;
	props.max = INT_MIN;
	while (i < length)
	{
		if (arr[i] < props.min)
			props.min = arr[i];
		if (arr[i] > props.max)
			props.max = arr[i];
		i++;
	}
	props.range = props.max - props.min + 1;
	props.offset = 0 - props.min;
	return (props);
}

void	run_count_sort(int *sorted_arr, t_count_node *count, int offset)
{
	int		i;
	t_count_node	*current;

	i = 0;
	current = count;
	while (current != NULL)
	{
		while (current->count > 0)
		{
			sorted_arr[i++] = current->value - offset;
			current->count--;
		}
		current = current->next;
	}
}

// void	compare_arrays(int *arr, int *sorted_arr, int length)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("Comparison of original and sorted arrays:\n");
// 	while (i < length)
// 	{
// 		ft_printf("Original: %d, Sorted: %d\n", arr[i], sorted_arr[i]);
// 		i++;
// 	}
// }

int	*sort_numbers(int *arr, int length)
{
	int				*sorted_arr;
	t_count_node	*count;
	t_count_props	props;

	props = get_props(arr, length);
	count = create_linked_list(props.range);
	populate_count_list(arr, length, count, props.offset);
	sorted_arr = (int *)malloc(length * sizeof(int));
	if (!sorted_arr)
	{
		ft_printf("Memory Allocation Failed");
		return (NULL);
	}
	run_count_sort(sorted_arr, count, props.offset);
	free_list(count);
	// compare_arrays(arr, sorted_arr, length);
	// free(sorted_arr);
	return (sorted_arr);
}

// void	free_arrays(int num_of_arrays, ...)
// {
// 	va_list	arrays;
// 	int		*arr;
// 	int		i;

// 	i = 0;
// 	while (i < num_of_arrays)
// 	{
// 		va_start(arrays, num_of_arrays);
// 		arr = va_arg(arrays, int *);
// 		free(arr);
// 		va_end(arrays);
// 		i++;
// 	}
// }

int	*get_ranks(int *arr, int length)
{
	int	*sorted_arr;
	int	*rank_arr;
	int	i;
	int	j;

	sorted_arr = sort_numbers(arr, length);
	if (!sorted_arr)
		return (NULL);
	rank_arr = (int *)malloc(length * sizeof(int));
	if (!rank_arr)
	{
		free(sorted_arr);
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		j = 0;
		while (arr[i] != sorted_arr[j])
			j++;
		rank_arr[i] = j;
		i++;
	}
	free(sorted_arr);
	return (rank_arr);
}
