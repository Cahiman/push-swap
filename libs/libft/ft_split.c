/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:45 by baiannon          #+#    #+#             */
/*   Updated: 2024/08/28 17:38:38 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **s)
{
	int	i;

	i = -1;
	if (s == NULL)
		return ;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s - 1);
}

static char	*new_word(char *str, char sep)
{
	int			i;
	static int	j = 0;
	int			len;
	char		*next_str;

	i = 0;
	len = 0;
	while (str[j] == sep)
		++j;
	while ((str[j + len] != sep) && str[j + len])
		++len;
	next_str = malloc(sizeof(char) * (len + 1));
	if (NULL == next_str)
		return (NULL);
	while ((str[j] != sep) && str[j])
		next_str[i++] = str[j++];
	next_str[i] = '\0';
	return (next_str);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char *str, char sep)
{
	int		nb_word;
	char	**tab;
	int		i;

	i = 0;
	nb_word = count_words(str, sep);
	if (!nb_word)
		exit(1);
	tab = malloc(sizeof(char *) * (nb_word + 2));
	if (NULL == tab)
		return (NULL);
	while (nb_word > 0)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof(char));
			if (NULL == tab[i])
				return (NULL);
			tab[i++][0] = '\0';
		}
		tab[i++] = new_word(str, sep);
		nb_word--;
	}
	tab[i] = NULL;
	return (tab);
}
