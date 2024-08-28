/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:02:40 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 18:12:36 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **list)
{
	t_node	*last_node;
	int		len;

	len = get_list_len(*list);
	if (list == NULL || *list == NULL || len == 1)
		return ;
	last_node = _last_node(*list);
	last_node->next = (*list);
	*list = (*list)->next;
	(*list)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}