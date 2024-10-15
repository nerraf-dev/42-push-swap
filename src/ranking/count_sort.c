/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:05:02 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/13 16:14:10 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_sort.h"

// t_count_props	get_props(int *arr, int length)
// {
// 	int				i;
// 	t_count_props	props;

// 	i = 0;
// 	props.min = INT_MAX;
// 	props.max = INT_MIN;
// 	while (i < length)
// 	{
// 		if (arr[i] < props.min)
// 			props.min = arr[i];
// 		if (arr[i] > props.max)
// 			props.max = arr[i];
// 		i++;
// 	}
// 	props.range = props.max - props.min + 1;
// 	props.offset = 0 - props.min;
// 	return (props);
// }

// void	run_count_sort(int *sorted_arr, t_node *count, int offset)
// {
// 	int		i;
// 	t_node	*current;

// 	i = 0;
// 	current = count;
// 	while (current != NULL)
// 	{
// 		while (current->count > 0)
// 		{
// 			sorted_arr[i++] = current->value - offset;
// 			current->count--;
// 		}
// 		current = current->next;
// 	}
// }

// // void	compare_arrays(int *arr, int *sorted_arr, int length)
// // {
// // 	int	i;

// // 	i = 0;
// // 	ft_printf("Comparison of original and sorted arrays:\n");
// // 	while (i < length)
// // 	{
// // 		ft_printf("Original: %d, Sorted: %d\n", arr[i], sorted_arr[i]);
// // 		i++;
// // 	}
// // }

// int	*sort_numbers(int *arr, int length)
// {
// 	int				*sorted_arr;
// 	t_node			*count;
// 	t_count_props	props;

// 	props = get_props(arr, length);
// 	count = create_linked_list(props.range);
// 	populate_count_list(arr, length, count, props.offset);
// 	sorted_arr = (int *)malloc(length * sizeof(int));
// 	if (!sorted_arr)
// 	{
// 		ft_printf("Memory Allocation Failed");
// 		return (NULL);
// 	}
// 	run_count_sort(sorted_arr, count, props.offset);
// 	free_list(count);
// 	// compare_arrays(arr, sorted_arr, length);
// 	// free(sorted_arr);
// 	return (sorted_arr);
// }


