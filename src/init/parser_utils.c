/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:14:18 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 12:18:46 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arg_parser.h"

int	int_array_length(int *int_array)
{
	int	i;

	i = 0;
	while (int_array[i])
		i++;
	return (i);
}

int	is_valid_int(const char *str)
{
	if (!ft_isdigit(str[0]) && str[0] != '-')
		return (0);
	return (1);
}

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
			handle_error("Invalid integer found", split, int_array);
		int_array[i] = ft_atoi(split[i]);
		i++;
	}
	return (int_array);
}

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

