/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:14:36 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/06 14:36:47 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arg_parser.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	*parse_single_arg(char **argv, int *arr_size)
{
	char	**split;
	int		*int_array;
	int		i;
	int		duplicates;

	split = ft_split(argv[1], ' ');
	if (!split)
		handle_error("Memory allocation failed", NULL, NULL);
	i = 0;
	while (split[i] != NULL)
	{
		if (!is_valid_int(split[i]))
			handle_error("Invalid integer found", split, NULL);
		i++;
	}
	*arr_size = i;
	int_array = convert_to_int_array(split, *arr_size);
	free_split(split);
	duplicates = has_duplicates(int_array, *arr_size);
	if (duplicates)
		handle_error("Duplicate values found", NULL, int_array);
	return (int_array);
}

static int	*parse_arguments(int argc, char **argv, int *arr_size)
{
	int		*int_array;
	int		i;
	int		duplicates;

	i = 1;
	*arr_size = argc - 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
			handle_error("Invalid integer found", NULL, NULL);
		i++;
	}
	int_array = convert_to_int_array(argv + 1, *arr_size);
	duplicates = has_duplicates(int_array, *arr_size);
	if (duplicates)
		handle_error("Duplicate values found", NULL, int_array);
	return (int_array);
}

int	*argument_parser(int argc, char **argv, int *arr_size)
{
	int	*int_array;

	int_array = NULL;
	if (argc == 1)
		handle_error("No arguments given", NULL, NULL);
	if (argc == 2)
		int_array = parse_single_arg(argv, arr_size);
	else
		int_array = parse_arguments(argc, argv, arr_size);
	if (!int_array)
		handle_error("Memory allocation failed", NULL, NULL);
	return (int_array);
}
