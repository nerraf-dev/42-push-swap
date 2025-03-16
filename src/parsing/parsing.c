/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:58:10 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:50:11 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Frees a split array of strings.
 *
 * @param split The array of strings to be freed.
 */
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

/**
 * @brief Splits the arguments into an array of strings.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return char** The split array of strings.
 */
static char	**split_arguments(int argc, char **argv)
{
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			handle_error(true, NULL, NULL);
	}
	else
		split = argv + 1;
	return (split);
}

/**
 * @brief Validates the arguments to ensure they are valid integers.
 *
 * @param split The split array of strings.
 * @param argc The argument count.
 */
static void	validate_arguments(char **split, int argc)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		if (!is_valid_int(split[i]))
		{
			if (argc == 2)
				handle_error(true, split, NULL);
			else
				handle_error(true, NULL, NULL);
		}
		i++;
	}
}

/**
 * @brief Parses the arguments into an array of integers.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param arr_size Pointer to store the size of the array.
 * @return int* The array of integers.
 */
static int	*parse_arguments(int argc, char **argv, int *arr_size)
{
	char	**split;
	int		*int_array;
	int		duplicates;

	split = split_arguments(argc, argv);
	validate_arguments(split, argc);
	*arr_size = split_length(split);
	int_array = convert_to_int_array(split, *arr_size);
	if (argc == 2)
		free_split(split);
	duplicates = has_duplicates(int_array, *arr_size);
	if (duplicates)
		handle_error(true, NULL, int_array);
	return (int_array);
}

/**
 * @brief Parses the command line arguments and returns an array of integers.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param arr_size Pointer to store the size of the array.
 * @return int* The array of integers.
 */
int	*argument_parser(int argc, char **argv, int *arr_size)
{
	int	*int_array;

	int_array = NULL;
	if (argc == 1)
		handle_error(false, NULL, NULL);
	int_array = parse_arguments(argc, argv, arr_size);
	if (!int_array)
		handle_error(true, NULL, NULL);
	return (int_array);
}
