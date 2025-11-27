/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:12:33 by smenard           #+#    #+#             */
/*   Updated: 2025/11/12 21:18:31 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_splitted(char **splitted, uint32_t k)
{
	while (k + 1 > 0)
	{
		free(splitted[k]);
		k--;
	}
	free(splitted);
	return (NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*extract_word(const char *s, char c, uint32_t *i)
{
	uint32_t		j;
	char			*word;

	word = NULL;
	while (s[*i] && s[*i] == c)
		(*i)++;
	j = *i;
	while (s[j] && s[j] != c)
		j++;
	if (*i < j)
	{
		word = ft_substr(s, *i, j - *i);
		if (!word)
			return ((char *) -1);
		*i = j;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char			**splitted;
	char			*curr_word;
	uint32_t		i;
	uint32_t		k;

	if (!s)
		return (ft_calloc(1, sizeof(char *)));
	splitted = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		curr_word = extract_word(s, c, &i);
		if (curr_word)
		{
			if (curr_word == (char *) -1)
				return (free_splitted(splitted, k));
			splitted[k++] = curr_word;
		}
	}
	return (splitted);
}
