/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo_prep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:21:35 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/29 17:32:56 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_and_median(t_node *list)
{
	int	pos;
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

static void	target(t_node *a, t_node *b)
{
	t_node	*node;
	t_node	*target;
	long	closest_big;

	while (b)
	{
		closest_big = LONG_MAX;
		node = a;
		while (node)
		{
			if (node->nbr > b->nbr && node->nbr < closest_big)
			{
				closest_big = node->nbr;
				target = node;
			}
			node = node->next;
		}
		if (closest_big == LONG_MAX)
			b->target = search_smallest_node_value(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	cost(t_node *a, t_node *b)
{
	int	a_len;
	int	b_len;

	a_len = get_list_len(a);
	b_len = get_list_len(b);
	while (b)
	{
		b->cost = b->pos;
		if (!(b->above_median))
			b->cost = b_len - (b->pos);
		if (b->target->above_median)
			b->cost += b->target->pos;
		else
			b->cost += a_len - (b->target->pos);
		b = b->next;
	}
}

static void	cheapest_cost(t_node *b)
{
	long	cheapest_cost;
	t_node	*cheapest_node;

	if (b == NULL)
		return ;
	cheapest_cost = LONG_MAX;
	while (b)
	{
		if (b->cost < cheapest_cost)
		{
			cheapest_cost = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	init_prep(t_node *a, t_node *b)
{
	pos_and_median(a);
	pos_and_median(b);
	target(a, b);
	cost(a, b);
	cheapest_cost(b);
}
