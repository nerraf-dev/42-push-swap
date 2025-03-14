/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:50:28 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/13 14:18:53 by sfarren          ###   ########.fr       */
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
    int		i;
    long	value;

    i = 0;
    while (split[i] != NULL)
    {
        ft_printf("Validating argument: %s\n", split[i]); // Debug print
        if (!is_valid_int(split[i]))
        {
            ft_printf("Invalid integer: %s\n", split[i]); // Debug print
            if (argc == 2)
                handle_error(true, split, NULL);
            else
                handle_error(true, NULL, NULL);
        }
        value = ft_atol(split[i]);
        ft_printf("Converted value: %ld\n", value); // Debug print
        if (value > INT_MAX || value < INT_MIN)
        {
            ft_printf("Value out of range: %ld\n", value); // Debug print
            if (argc == 2)
                handle_error(true, split, NULL);
            else
                handle_error(true, NULL, NULL);
        }
        i++;
        ft_printf("Next index: %d\n", i); // Debug print
    }
    ft_printf("Finished validating arguments\n"); // Debug print
}

static int	*parse_arguments(int argc, char **argv, int *arr_size)
{
    char	**split;
    int		*int_array;
    int		duplicates;

    ft_printf("Parsing arguments\n"); // Debug print
    split = split_arguments(argc, argv);
    validate_arguments(split, argc);
    *arr_size = split_length(split);
    ft_printf("Array size: %d\n", *arr_size); // Debug print
    int_array = convert_to_int_array(split, *arr_size);
    if (argc == 2)
        free_split(split);
    duplicates = has_duplicates(int_array, *arr_size);
    if (duplicates)
        handle_error(true, NULL, int_array);
    ft_printf("Finished parsing arguments\n"); // Debug print
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
