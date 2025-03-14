/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           #+#    #+#             */
/*   Updated: 2025/03/07 10:09:23 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static int	*parse_arguments(int argc, char **argv, int *arr_size)
{
	char	**split;
	int		*int_array;
	int		duplicates;

	split = split_arguments(argc, argv);
	validate_arguments(split, argc);
	*arr_size = split_length(split); // Use split_length instead of int_array_length
	int_array = convert_to_int_array(split, *arr_size);
	if (argc == 2)
		free_split(split);
	duplicates = has_duplicates(int_array, *arr_size);
	if (duplicates)
		handle_error(true, NULL, int_array);
	return (int_array);
}

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
