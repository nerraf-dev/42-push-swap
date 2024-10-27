/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:28:29 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/26 19:40:15 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
				t_stack_node *lc_node)
{
	while (*stack_b != lc_node && *stack_a != lc_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void rev_rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
				t_stack_node *lc_node)
{
	while (*stack_b != lc_node && *stack_a != lc_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*lc_node;

	lc_node = get_lc_node(*stack_a);
	if (lc_node->above_median && lc_node->target->above_median)
		rotate_stacks(stack_a, stack_b, lc_node);
	else if (!(lc_node->above_median) && !(lc_node->target->above_median))
		rev_rotate_stacks(stack_a, stack_b, lc_node);
	push_prep(stack_a, lc_node, 'a');
	push_prep(stack_b, lc_node->target, 'b');
	pb(stack_a, stack_b);
}

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int		len;

	ft_printf("---STACK A START---\n");
	print_stack(*stack_a, "A");
	len = stack_size(*stack_a);
	// First 2 elements are pushed to stack B no matter what!
	if (len-- > 3)
		pb(stack_a, stack_b);
	if (len-- > 3)
		pb(stack_a, stack_b);
	// While stack a is still > 3 and not sorted
	//		find the lowest cost node and push it to stack b
	while (len-- > 3 && !stack_sorted(*stack_a))
	{
		//init nodes in stack `a`:
		//	- set index values on `a` and `b`
		//	- set target values on `a`
		//	- calculate & set cost values on `a`
		//	- set lowest_cost flag on `a`
		initialise_nodes_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
	}
	ft_printf("---STACK A---\n");
	print_stack(*stack_a, "A");
	ft_printf("---STACK B - AFTER INITIAL PUSH---\n");
	print_stack(*stack_b, "B");
	sort_small(stack_a, stack_b);
	while (stack_b)
	{
		// Debugging: Print the current state of stack_b before initialise_b_nodes and push_b_to_a
		ft_printf("Before initialise_b_nodes and push_b_to_a:\n");
		print_stack(*stack_b, "B");

		initialise_b_nodes(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);

		// Debugging: Print the current state of stack_b after push_b_to_a
		ft_printf("After initialise_b_nodes and push_b_to_a:\n");
		print_stack(*stack_b, "B");
	}
	ft_printf("-----------------------------------\n");
	ft_printf("---STACK A - AFTER SORTING---\n");
	print_stack(*stack_a, "A");
	ft_printf("---STACK B - AFTER SORTING---\n");
	print_stack(*stack_b, "B");
	// -------------------------
	current_index(*stack_a);
	min_to_top(stack_a);
}
