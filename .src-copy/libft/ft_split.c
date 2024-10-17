/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:07:03 by sfarren           #+#    #+#             */
/*   Updated: 2024/06/01 19:22:19 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static char	**init_words(char const *s, char c)
{
	size_t	count;
	char	**words;

	count = word_count(s, c);
	words = ft_calloc(count + 1, sizeof(char *));
	if (!words)
		return (0);
	return (words);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

/*
 * Splits a string into an array of substrings based on a delimiter character.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of substrings, or NULL if memory allocation fails.
 */

char	**ft_split(const char *s, char c)
{
	char	**words;
	t_vars	vars;

	vars.i = 0;
	vars.j = 0;
	vars.s_word = -1;
	words = init_words(s, c);
	if (!words)
		return (0);
	while (vars.i <= ft_strlen(s))
	{
		if (s[vars.i] != c && vars.s_word < 0)
			vars.s_word = vars.i;
		else if ((s[vars.i] == c || s[vars.i] == '\0') && vars.s_word >= 0)
		{
			words[vars.j] = fill_word(s, vars.s_word, vars.i);
			if (!(words[vars.j]))
				return (ft_free(words, vars.j));
			vars.s_word = -1;
			vars.j++;
		}
		vars.i++;
	}
	return (words);
}
