/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:07:35 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 15:03:07 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/push_swap.h"
#include "../../includes/init.h"

void	print_and_exit(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

// static void print_free_and_exit(char *str, ...)
// {
// 	va_list	args;
// 	int		count;
// 	int		i;
// 	void	*ptr;

// 	count = 0;
// 	while (args)
// 		count++;
// 	va_start(args, count);
// 	i = 0;
// 	while (i < count)
// 	{
// 		ptr = va_arg(args, void *);
// 		free(ptr);
// 	}
// 	va_end(args);
// 	ft_printf("%s", str);
// 	exit(1);
// }

static int	*validate_integers(char **words_arr, int *int_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (is_valid_integer(words_arr[i]))
		{
			int_arr[i] = ft_atoi(words_arr[i]);
			free(words_arr[i]);
			i++;
		}
		else
		{
			while (i < len)
				free(words_arr[i++]);
			free(words_arr);
			free(int_arr);
			print_and_exit("Error: Invalid Integer\n");
		}
	}
	return (int_arr);
}

void	free_split(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	*parse_string(char **argv)
{
	int		*arr;
	int		i;
	char	**split;

	split = ft_split(argv[1], ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	arr = (int *)malloc(i * sizeof(int));
	if (!arr)
	{
		ft_printf("Memory allocation failed");
		free_split(split);
		return (NULL);
	}
	arr = validate_integers(split, arr, i);
	free_split(split);
	return (arr);
}

void	parse_arguments(int argc, char **argv, int **dst_arr)
{
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		if (is_valid_integer(argv[i + 1]))
			(*dst_arr)[i] = ft_atoi(argv[i + 1]);
		else
			print_and_exit("Error: Invalid Integer\n");
	}
}
