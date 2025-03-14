/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/13 19:12:47 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_b)
	{
		push_prep(stack_a, (*stack_b)->target, 'a');
		pa(stack_a, stack_b);
	}
}

// static void	sort_two(t_stack_node	**stack)
// {
// 	if (!*stack || !(*stack)->next)
// 		return ;
// 	if ((*stack)->value > (*stack)->next->value)
// 		sa(stack);
// }

// static void	sort_three(t_stack_node	**stack)
// {
// 	t_stack_node	*current;
// 	int				max;

// 	current = *stack;
// 	max = get_max(current);
// 	if (current->value == max)
// 		ra(stack);
// 	else if (current->next->value == max)
// 		rra(stack);
// 	if ((*stack)->value > (*stack)->next->value)
// 		sa(stack);
// }
static int	big_int(int *int_array, int arr_size)
{
	int	i;
	int	max;

	i = 0;
	max = int_array[0];
	while (i < arr_size)
	{
		if (int_array[i] > max)
			max = int_array[i];
		i++;
	}
	return (max);
}

void	sort_small(int *int_array, int arr_size)
{
	int	max;

	max = big_int(int_array, arr_size);
	ft_printf("Max: %d\n", max);
	if (arr_size == 2)
	{
		if (int_array[0] > int_array[1])
			ft_printf("sa\n");
	}
	else if (arr_size == 3)
	{
		ft_printf("int_array[0]: %d\n", int_array[0]);
		if (int_array[0] == max)
			ft_printf("ra\n");
		else if (int_array[1] == max)
			ft_printf("rra\n");
		if (int_array[0] > int_array[1])
			ft_printf("sa\n");
	}
}
