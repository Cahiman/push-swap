/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:08:55 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/29 17:32:23 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_node **list)
{
	t_node	*last_node;
	int		len;

	len = get_list_len(*list);
	if (*list == NULL || list == NULL || len == 1)
		return ;
	last_node = _last_node(*list);
	last_node->prev->next = NULL;
	last_node->next = *list;
	last_node->prev = NULL;
	*list = last_node;
	last_node->next->prev = last_node;
}

void	ft_rra(t_node **a)
{
	reverse(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_node **b)
{
	reverse(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_node **a, t_node **b)
{
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}
