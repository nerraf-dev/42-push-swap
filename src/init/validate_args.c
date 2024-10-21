/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:26:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 14:38:53 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"
// #include "../../includes/push_swap.h"

int	array_length(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*validate_args(int argc, char **argv)
{
	int	*arr;
	int	arr_len;

	if (argc == 2)
		arr = parse_string(argv);
	else
	{
		arr = (int *)malloc(sizeof(int) * (argc - 1));
		if (!arr)
		{
			ft_printf("Memory allocation failed\n");
			exit(1);
		}
		parse_arguments(argc, argv, &arr);
	}
	if (!arr)
		return (NULL);
	arr_len = array_length(arr);
	if (check_duplicates(arr, arr_len))
	{
		ft_printf("ERROR: Duplicate values\n");
		free(arr);
		exit(1);
	}
	return (arr);
}
