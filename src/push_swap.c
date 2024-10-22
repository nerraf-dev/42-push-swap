/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/22 12:35:48 by sfarren          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	// t_stack_node		*stack_a;
	//t_stack_node	*stack_b;
	// int			len;
	char			**values;
	int				i;

	// stack_a = NULL;
	// stack_b = NULL;

	// Check Arguments:
	// 1. Check if there are any arguments
	// 2. Check if the arguments are valid integers
	// 3. Check if there are any duplicates
	// 4. Parse the arguments into an array of integers
	// 5. Initialise the stack
	// 6. Populate the stack with the parsed arguments
	// 7. Check if the stack is sorted
	// 8. Sort the stack
	// 9. Free the stack
	// 10. Return 0

	// No arguments
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		values = ft_split(argv[1], ' ');
		// Check if the arguments are valid integers

		i = 0;
		while (values[i])
		{
			if (!is_valid_integer(values[i]))
			{
				ft_printf("Error\n");
				free_split(values);
				return (1);
			}
			ft_printf("%s\n", values[i]);
			i++;
		}
	}
	free_split(values);
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
