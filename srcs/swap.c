/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:28:04 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 18:04:26 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **list)
{
	int	len;

	len = get_list_len(*list);
	if (*list == NULL || list == NULL || len == 1)
		return ;
	*list = (*list)->next;
	(*list)->prev->prev = *list;
	(*list)->prev->next = (*list)->next;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	(*list)->next = (*list)->prev;
	(*list)->prev = NULL;
}

void	ft_sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
