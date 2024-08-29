/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:15:52 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/29 17:32:38 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_lists(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		ft_rr(a, b);
	pos_and_median(*a);
	pos_and_median(*b);
}

static void	reverse_rotate_lists(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		ft_rrr(a, b);
	pos_and_median(*a);
	pos_and_median(*b);
}

void	sort_node_in_other_stack(t_node **first_node, t_node *node_to_put_top,
		char a_or_b)
{
	while (*first_node != node_to_put_top)
	{
		if (a_or_b == 'a')
		{
			if (node_to_put_top->above_median)
				ft_ra(first_node);
			else
				ft_rra(first_node);
		}
		if (a_or_b == 'b')
		{
			if (node_to_put_top->above_median)
				ft_rb(first_node);
			else
				ft_rrb(first_node);
		}
	}
}

static void	nodes_to_top_and_push(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_lists(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_lists(a, b, cheapest);
	sort_node_in_other_stack(a, cheapest->target, 'a');
	sort_node_in_other_stack(b, cheapest, 'b');
	ft_pa(a, b);
}

void	sorting_algo(t_node **a, t_node **b)
{
	t_node	*smallest_node_value;
	int		a_len;

	a_len = get_list_len(*a);
	while (a_len > 3)
	{
		ft_pb(b, a);
		a_len--;
	}
	sort_three(a);
	while (*b)
	{
		init_prep(*a, *b);
		nodes_to_top_and_push(a, b);
	}
	pos_and_median(*a);
	smallest_node_value = search_smallest_node_value(*a);
	if (smallest_node_value->above_median)
		while (*a != smallest_node_value)
			ft_ra(a);
	else
		while (*a != smallest_node_value)
			ft_rra(a);
}
