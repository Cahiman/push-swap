/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:05:46 by baiannon          #+#    #+#             */
/*   Updated: 2024/07/10 17:19:17 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dest = malloc((len + 2) * sizeof(char));
	if (!s)
		return (NULL);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = ' ';
	dest[i + 1] = '\0';
	return (dest);
}
