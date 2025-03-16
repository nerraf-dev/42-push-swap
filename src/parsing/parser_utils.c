/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:14:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:50:06 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Calculates the length of an integer array.
 *
 * @param int_array The integer array.
 * @return int The length of the array.
 */
int	int_array_length(int *int_array)
{
	int	i;

	i = 0;
	while (int_array[i])
		i++;
	return (i);
}

/**
 * @brief Converts a split array of strings to an array of integers.
 *
 * @param split The split array of strings.
 * @param size The size of the array.
 * @return int* The array of integers.
 */
int	*convert_to_int_array(char **split, int size)
{
	int	*int_array;
	int	i;

	int_array = (int *)malloc(size * sizeof(int));
	if (!int_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!is_valid_int(split[i]))
			handle_error(true, split, int_array);
		int_array[i] = ft_atoi(split[i]);
		i++;
	}
	return (int_array);
}

/**
 * @brief Checks if an array of integers contains duplicates.
 *
 * @param arr The array of integers.
 * @param size The size of the array.
 * @return int 1 if duplicates are found, 0 otherwise.
 */
int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Calculates the length of a split array of strings.
 *
 * @param split The split array of strings.
 * @return int The length of the array.
 */
int	split_length(char **split)
{
	int	length;

	length = 0;
	while (split[length] != NULL)
	{
		length++;
	}
	return (length);
}
