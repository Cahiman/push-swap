/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:48:04 by baiannon          #+#    #+#             */
/*   Updated: 2024/09/02 17:55:38 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_len(t_node *list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	init_list(t_node **a, char **args, bool two_args)
{
	int		i;
	long	nbr;

	i = 0;
	while (args[i])
	{
		if (check_number(args[i]) == 1)
			free_errors(a, args, two_args);
		nbr = ft_atol(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a, args, two_args);
		if (check_for_doublon(*a, nbr) == 1)
			free_errors(a, args, two_args);
		new_node(a, (int)nbr);
		i++;
	}
	if (two_args)
		ft_free(args);
}

void	new_node(t_node **stack, int nbr)
{
	t_node	*new_node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = _last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
