/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/22 12:11:22 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"
#include "../../includes/push_swap.h"


// Function to populate the stack
// static void	populate_stack(t_stack_node	**top, int *arr, int len)
// {
// 	t_stack_node	*new_node;
// 	int				i;

// 	i = len -1;
// 	while (i >= 0)
// 	{
// 		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
// 		if (!new_node)
// 		{
// 			ft_printf("Memory allocation failed");
// 			return ;
// 		}
// 		new_node->value = arr[i];
// 		new_node->cost = 0;
// 		new_node->next = *top;
// 		new_node->prev = NULL;
// 		i--;
// 	}
// }

void	populate_stack(t_stack_node **stack, char **values)
{
	int i = 0;

	if (!stack || !values)
		return;

	while (values[i]) {
		append_node(stack, ft_atoi(values[i]));
		i++;
	}
	free_split(values); // Ensure values are freed after use
}

void	find_dupes(int *arr, int arr_len)
{
	if (check_duplicates(arr, arr_len))
		{
			ft_printf("ERROR: Duplicate values\n");
			free(arr);
			exit(1);
		}
}
void	initialise_stack(t_stack_node **top, int argc, char **argv)
{
	int	*arr;
	int	arr_len;

	*top = NULL;
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
		return ;
	arr_len = array_length(arr);
	find_dupes(arr, arr_len);
	// populate_stack(top, *arr);
	free(arr);
}
