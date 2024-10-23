/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:07:35 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/23 14:35:36 by sfarren          ###   ########.fr       */
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

static int	*validate_integers(char **src, int *dst, int len, bool is_split)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("src[i]: %s\n", src[i]);
		if (!is_valid_integer(src[i]))
		{
			if (is_split)
				free_split(src);
			free(dst);
			print_and_exit("Invalid integer");
		}
		dst[i] = ft_atoi(src[i]);
		i++;
	}
	if (is_split)
		free(src);
	return (dst);
}

void	free_split(char **words)
{
	int i = 0;

	if (!words)
		return ;
	while (words[i])
	{
		free(words[i]);
		words[i] = NULL; // Set to NULL after freeing
		i++;
	}
	free(words);
	words = NULL; // Set to NULL after freeing
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
	arr = validate_integers(split, arr, i, true);
	// free_split(split);
	return (arr);
}

int	*parse_arguments(int argc, char **argv, int *size)
{
	// int		i;
	int		*arr;
	// char	**split;

	// i = 0;
	arr = NULL;
	if (argc == 2)
	{
		ft_printf("argc == 2\n");
		arr = parse_string(argv);
		if (!arr)
			return (NULL);
		*size = array_length(arr);
	}
	else if (argc > 2)
	{
		ft_printf("argc > 2\n");
		arr = (int *)malloc(sizeof(int) * (argc -1));
		if (!arr)
			print_and_exit("Memory allocation failed");
		arr = validate_integers(argv + 1, arr, argc - 1, false);
		// while (i < argc - 1)
		// {
		// 	ft_printf("%d\n", arr[i]);
		// 	i++;
		// }
	}
	else
		print_and_exit("No args");
	return (arr);
}
