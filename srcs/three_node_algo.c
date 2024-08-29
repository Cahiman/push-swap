/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_node_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:48:44 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/29 17:30:56 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest_node(*a);
	if (*a == biggest_node)
		ft_ra(a);
	else if ((*a)->next == biggest_node)
		ft_rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a);
}
