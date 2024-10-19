/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:07:35 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/19 12:46:46 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*parse_arguments(int argc, char **argv)
{
	int		*arr;
	int		i;
	int		j;
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		i = 0;
		while (split[i] != NULL)
			i++;
		arr = (int *)malloc(i * sizeof(int));
		if (!arr)
		{
			ft_printf("Memory allocation failed");
			return (NULL);
		}
		j = 0;
		while (j < i)
		{
			arr[j] = ft_atoi(split[j]);
			free(split[j]);
			j++;
		}
		free(split);
	}
	else
	{
		arr = (int *)malloc((argc - 1) * sizeof(int));
		if (!arr)
		{
			ft_printf("Memory allocation failed");
			return (NULL);
		}
		i = 0;
		while (i < argc - 1)
		{
			arr[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	// i = 0;
	// while (i < argc -1)
	// {
	// 	ft_printf("Arr[%d]: %d\n", i, arr[i]);
	// 	i++;
	// }

	return (arr);
}

	// i = 0;
	// while (i < argc - 1)
	// {
	// 	if (!is_valid_integer(argv[i + 1]))
	// 	{
	// 		ft_printf("Invalid integer");
	// 		return (NULL);
	// 	}
	// 	arr[i] = ft_atoi(argv[i + 1]);
	// 	i++;
	// }
