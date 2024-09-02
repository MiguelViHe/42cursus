/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_awk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:35:41 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/02 17:07:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			counter++;
			if (s[i] == '\'')
				flag = 1;
			while ((s[i] && s[i] != c) || flag == 1)
			{
				i++;
				if (s[i] == '\'')
					flag = 0;
			}
		}
	}
	return (counter);
}

static char	*copy_word(char const *s, int i, char *word, size_t word_len)
{
	int	j;

	j = 0;
	if (s[i - 1] == '\'')
		i -= 1;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static size_t	calc_word_len(char const *s, char c, int *i)
{
	size_t	word_len;
	int		spc_allowed;

	word_len = 0;
	spc_allowed = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	if (s[*i] == '\'')
		spc_allowed = 1;
	while ((s[*i] && s[*i] != c) || spc_allowed)
	{
		if (s[*i] != '\'')
			word_len++;
		(*i)++;
		if (s[*i] == '\'')
			spc_allowed = 0;
	}
	return (word_len);
}

static char	**fill_words(char const *s, char c, char **words, size_t num_words)
{
	size_t	word_len;
	int		i;
	size_t	word;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		word_len = calc_word_len(s, c, &i);
		words[word] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!words[word])
			return (free_array_split(words, word));
		words[word] = copy_word(s, i, words[word], word_len);
		word++;
		word_len = 0;
	}
	return (words);
}

/*Allocate (with malloc) and returns an array of strings obtained
by splitting s with the character c, used as delimiter.*/
char	**ft_split_awk(char const *s, char c)
{
	char	**words;
	size_t	num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	words = (char **)ft_calloc((num_words + 1), sizeof(char *));
	if (!words)
		return (NULL);
	words = fill_words(s, c, words, num_words);
	return (words);
}
