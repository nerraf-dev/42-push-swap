/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sort.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:18:15 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/14 14:15:00 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_SORT_H
# define C_SORT_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

// # include "../push_swap.h"

typedef struct s_count_props
{
	int		min;
	int		max;
	int		range;
	int		offset;
}	t_count_props;

int		*sort_numbers(int *arr, int length);
int		*get_ranks(int *arr, int length);

// LIST_UTILS
typedef struct s_count_node
{
	int				value;
	int				count;
	struct s_count_node	*next;
}				t_count_node;

typedef struct s_count_list
{
	t_count_node	*top;
}	t_count_list;

// *** LIST_UTILS ***
/**
 * @brief Creates a new node with the given value.
 *
 * @param value The value to be stored in the new node.
 * @return A pointer to the newly created node.
 */
t_count_node	*create_count_node(int value);

/**
 * @brief Creates a linked list with nodes ranging from 0 to the specified range.
 *
 * initializes a linked list where each node contains an integer value.
 * The values start from 0 and increment by 1 up to the specified range.
 *
 * @param length Number of nodes to be created.
 * @return A pointer to the head of the created linked list.
 */
t_count_node	*create_linked_list(int length);

/**
 * @brief Populates a count list based on the given array and linked list.
 *
 * This function takes an array, length, linked list head, an offset value.
 * It processes the array and linked list to populate a count list.
 *
 * @param arr Pointer to the integer array to be processed.
 * @param length The length of the integer array.
 * @param head Pointer to the head of the linked list (t_count_node).
 * @param offset The offset value to be used in the processing.
 */
void	populate_count_list(int *arr, int length, t_count_node *head, int offset);

/**
 * @brief Frees the memory allocated for a linked list.
 *
 * This function traverses through the linked list starting from the given node
 * and frees the memory allocated for each node in the list.
 *
 * @param count A pointer to the first node of the linked list to be freed.
 */
void	free_list(t_count_node *count);


#endif
