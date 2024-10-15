/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:20 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/15 10:58:29 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// // 	if input is 0 1 2, then return

// char	*sort_two(t_stack *stack, int *arr, int min, int max)
// {
// 	static char	*instructions;

// 	if (arr[0] == max && arr[1] == min)
// 	{
// 		swap(stack);
// 		return (instructions = "sa\n");
// 	}
// 	return (instructions = "none required\n");
// }

// char	*sort_three(t_stack *stack, int *arr, int min, int max)
// {
// 	char	*instructions;

// 	if (arr[0] == min && arr[1] == max)
// 	{
// 		swap(stack);
// 		rotate(stack);
// 		return (instructions = "sa,ra\n");
// 	}
// 	if (arr[0] == max && arr[1] == min)
// 	{
// 		rotate(stack);
// 		return (instructions = "ra\n");
// 	}
// 	if (arr[0] == max && arr[2] == min)
// 	{
// 		swap(stack);
// 		reverse_rotate(stack);
// 		return (instructions = "sa,rra\n");
// 	}

// 	return (instructions = "");
// }
