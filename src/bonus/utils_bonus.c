/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:27:15 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/27 13:56:06 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	rotate_both(t_stack_node **a, t_stack_node **b, bool rev)
{
	if (!rev)
	{
		rotate(a);
		rotate(b);
	}
	else
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

static void	swap_both(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}

int	execute_operation(char *op, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(op, "sa") == 0)
		swap(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap(b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(a, b);
	else if (ft_strcmp(op, "pa") == 0)
		push(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		push(b, a);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(a, b, false);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(op, "rrr") == 0)
		rotate_both(a, b, true);
	else
		return (0);
	return (1);
}
