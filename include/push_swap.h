/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:06:49 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 18:13:59 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int					nbr;
	int					pos;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}						t_node;

int	free_errors(t_node **a, char **split, bool two_args);
int	check_number(char *n);
int	check_for_doublon(t_node *a, int nbr);
int	get_list_len(t_node *list);

long	ft_atol(const char *nptr);

void	sort_three(t_node **a);
void	new_node(t_node **stack, int nbr);
void	init_list(t_node **a, char **args, bool two_args);

bool	list_sorted(t_node *list);

t_node *find_biggest_node(t_node *list);
t_node *_last_node(t_node *node);

/* *****************COMMANDS******************** */

void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);

void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);

void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);

#endif