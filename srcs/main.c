/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:05:59 by baiannon          #+#    #+#             */
/*   Updated: 2024/09/02 17:54:58 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if ((ac == 1) || (ac == 2 && !av[1][0]))
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
			return (1);
	}
	init_list(&a, av + 1, ac == 2);
	if (!list_sorted(a))
	{
		if (get_list_len(a) == 2)
			ft_sa(&a);
		else if (get_list_len(a) == 3)
			sort_three(&a);
		else
			sorting_algo(&a, &b);
	}
	free_node(&a);
	return (0);
}
