/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 13:39:39 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*initialise_stack(int *arr, int size)
{
	t_stack_node	*head;
	t_stack_node	*new_node;
	int				i;

	head = NULL;
	new_node = NULL;
	if (arr == NULL)
		return (head);
	i = size - 1;
	while (i >= 0)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (!new_node)
			return (NULL);
		new_node->value = arr[i];
		new_node->target_val = 0;
		new_node->next = head;
		new_node->prev = NULL;
		new_node->target = NULL;
		if (head != NULL)
			head->prev = new_node;
		head = new_node;
		i--;
	}
	return (head);
}
