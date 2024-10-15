/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:39:44 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/14 14:40:37 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	print_error_and_exit(const char *message, int *arr)
{
	ft_printf("%s\n", message);
	if (arr)
		free(arr);
	exit(1);
}

static int	*parse_arguments(int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr)
		print_error_and_exit("Memory allocation failed", NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (!is_valid_integer(argv[i + 1]))
			print_error_and_exit("Invalid integer", arr);
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	int	*arr;

	if (argc <= 1)
		print_error_and_exit("No arguments provided", NULL);
	arr = parse_arguments(argc, argv);
	if (check_duplicates(arr, argc - 1))
		print_error_and_exit("Error: Duplicate number", arr);
	// Find the sorted solution
	push_swap(arr, argc - 1);

	free(arr);
	return (0);
}
