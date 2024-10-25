/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:00:45 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 12:06:01 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/init.h"

int	main(int argc, char **argv)
{
	int		*int_array;
	int		arr_size;
	int		i;

	arr_size = 0;
	int_array = argument_parser(argc, argv, &arr_size);

	// free(int_array);
	free(int_array);
	// END OF MAIN
	return (0);
}
