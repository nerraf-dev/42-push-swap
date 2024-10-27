/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/26 19:43:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_b)
	{
		// Debugging: Print the current state of stack_b before push_prep
		ft_printf("Before push_prep:\n");
		print_stack(*stack_b, "B");

		push_prep(stack_a, (*stack_b)->target, 'a');

		// Debugging: Print the current state of stack_b before pa
		ft_printf("Before pa:\n");
		print_stack(*stack_b, "B");

		pa(stack_a, stack_b);

		// Debugging: Print the current state of stack_b after pa
		ft_printf("After pa:\n");
		print_stack(*stack_b, "B");\

		// Update stack_b to point to the next node
        if (*stack_b == NULL)
        {
            ft_printf("stack_b is now NULL\n");
        }
	}
}

void	sort_two(t_stack_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
	}
}

void	sort_three(t_stack_node	**stack)
{
	t_stack_node	*current;
	int				max;

	current = *stack;
	max = get_max(current);
	if (current->value == max)
		ra(stack);
	else if (current->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_small(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	if (stack_size(*stack_a) == 2)
		sort_two(stack_a);
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else
	{
		while (stack_size(*stack_a) > 3)
			pb(stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b)
		{
			// init stack_b nodes
			initialise_b_nodes(*stack_a, *stack_b);
			//move b to a
			push_b_to_a(stack_a, stack_b);
		}
		current_index(*stack_a);
		min_to_top(stack_a);
	}

}
