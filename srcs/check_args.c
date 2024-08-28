/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:26:53 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 16:56:54 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_number(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-' || n[i] == '+')
		i++;
	if (n[i] == '\0')
		return (1);
	while (ft_isdigit(n[i]))
		i++;
	if (n[i] != '\0')
		return (1);
	return (0);
}

int	check_for_doublon(t_node *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}