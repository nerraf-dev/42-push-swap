/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/23 16:26:15 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/init.h"

// static void	check_stack_output(t_stack_node *stack_a, t_stack_node *stack_b)
// {
// 		 // Debug prints to check final stack states
// 	ft_printf("Final stack A\n");
// 	print_stack(stack_a);
// 	ft_printf("Final stack B\n");
// 	print_stack(stack_b);
// }

// static int	check_integers(char **values)
// {
// 	int	i;

// 	i = 0;
// 	while (values[i])
// 	{
// 		if (!is_valid_integer(values[i]))
// 		{
// 			ft_printf("Error\n");
// 			free_split(values);
// 			return (1);
// 		}

// 		ft_printf("%s\n", values[i]);
// 		i++;
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int		*values;
	int		size;
	int		i;

	// Check Arguments:
	// 2. Check if the arguments are valid integers
	// 3. Check if there are any duplicates
	// 4. Parse the arguments into an array of integers
	// 5. Initialise the stack
	// 6. Populate the stack with the parsed arguments
	// 7. Check if the stack is sorted
	// 8. Sort the stack
	// 9. Free the stack
	// 10. Return 0
	values = NULL;
	// No arguments
	if (argc == 1)
		return (1);
	// arr is allocated in parse arguments
	// arr `values` is allocated memory in parse_arguments or parse_string
	// parse_arguments is called in main
	// if argc is 2, parse_string is called
	// parse_string splits argv[1] which contains the string of ints/a single int
	// array arr is allocated memory based on the size of split (alloc'd in ft_split)
	// arr is then validated in validate_integers
	// no memory is allocated here. Iterate through source array and validate each element
	// if an invalid integer is found and src came from a split operation
	//		- src is free - created as result of ft_split, dts is free created in parse_string
	//	if is_split (means argc == 2) free src is called which should clean up after the split
	// dst is returned to parse_string, stored as `arr`

	values = parse_arguments(argc, argv, &size);
	if (values == NULL)
		return (1);

	ft_printf("Size (from main)- %d\n", size);
	// print values
	i = 0;
	while (i < size)
	{
		ft_printf("values[%d]: %d\n", i, values[i]);
		i++;
	}



	free(values);
	//If argc == 2 the argument could be a single number, e.g. 17, or a string of numbers, "3 14 2"

	// initialise_stack(&stack_a, argc, argv);
	// print_stack(stack_a, 'a');
	// len = stack_len(stack_a);
	// if (!stack_sorted(stack_a))
	// {
	// 	if (len == 2)
	// 		sort_two(&stack_a);
	// 	else if (len == 3)
	// 		sort_three(&stack_a);
	// 	// else
	// 	// 	sort_big(&stack_a, &stack_b);
	// }

	// print_stack(stack_a, 'a');
	// free_stack(&stack_a);
	// free_stack(stack_b);
	return (0);
}
