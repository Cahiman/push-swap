/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:54:54 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/29 16:51:16 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **end, t_node **start)
{
	t_node	*first_node;

	if (*start == NULL)
		return ;
	first_node = *start;
	*start = (*start)->next;
	if (*start)
		(*start)->prev = NULL;
	first_node->prev = NULL;
	if (*end == NULL)
	{
		*end = first_node;
		first_node->next = NULL;
	}
	else
	{
		first_node->next = *end;
		first_node->next->prev = first_node;
		*end = first_node;
	}
}

void	ft_pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	ft_pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}