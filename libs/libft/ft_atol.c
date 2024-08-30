/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:49:56 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/30 10:41:37 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long int	n;
	long int	res;
	long int	sign;

	n = 0;
	res = 0;
	sign = 1;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+')
		n++;
	else if (nptr[n] == '-')
	{
		sign *= -1;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		res = res * 10 + nptr[n] - '0';
		n++;
	}
	return (res * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main()
// {
// 	char str[]="   +123ab567";

// 	printf("%d\n", ft_atol(str));
// 	printf("%d\n", atoi(str));
// }