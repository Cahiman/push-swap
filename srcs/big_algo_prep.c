/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_prep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:21:35 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 18:36:13 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_and_median(t_node *list)
{
	int pos;
	int	median;

	pos = 0;
	if (list == NULL)
		return ;
	median = get_list_len(list) / 2;
	while (list)
	{
		list->pos = pos;
		if (pos <= median)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		pos++;
	}
}

static void target(t_node *a, t_node *b)
{}z