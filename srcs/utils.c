/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:07:18 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 17:58:00 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *_last_node(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

bool	list_sorted(t_node *list)
{
	if (list == NULL)
		return (1);
	while (list->next)
	{
		if (list->nbr > list->next->nbr)
			return (false);
		list = list->next;
	}
	return (true);
}

int	get_list_len(t_node *list)
{
	int i;

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

t_node *find_biggest_node(t_node *list)
{
	int	i;
	t_node *biggest_node;

	if (list == NULL)
		return (NULL);
	i = INT_MIN;
	while (list)
	{
		if (list->nbr > i)
		{
			biggest_node = list;
			i = list->nbr;
		}
		list = list->next;
	}	
	return (biggest_node);
}