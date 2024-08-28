/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:34:59 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 16:47:03 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node **stack)
{
	t_node *tmp_node;
	t_node *current_node;

	if (stack == NULL)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp_node = current_node->next;
		free(current_node);
		current_node = tmp_node;
	}
	*stack = NULL;
}

int	free_errors(t_node **a, char **split, bool two_args)
{
	free_node(a);
	if (two_args)
		ft_free(split);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}