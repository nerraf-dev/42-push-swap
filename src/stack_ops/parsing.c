/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:07:35 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 13:09:19 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*parse_arguments(int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr)
	{
		ft_printf("Memory allocation failed");
		return (NULL);
	}
	i = 0;
	while (i < argc - 1)
	{
		if (!is_valid_integer(argv[i + 1]))
		{
			ft_printf("Invalid integer");
			return (NULL);
		}
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}
