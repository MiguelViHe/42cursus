/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:06:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/19 10:06:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static char	**free_array(char **words, size_t word)
{
	while (word > 0)
	{
		word--;
		free(words[word]);
	}
	free(words);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	*copy_word(char const *s, int i, char *word, size_t word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
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
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			word_len++;
			i++;
		}
		words[word] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!words[word])
			return (free_array(words, word));
		words[word] = copy_word(s, i, words[word], word_len);
		word++;
		word_len = 0;
	}
	return (words);
}

/*Allocate (with malloc) and returns an array of strings obtained
by splitting s with the character c, used as delimiter.*/
char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	num_words;

	num_words = count_words(s, c);
	words = (char **)ft_calloc((num_words + 1), sizeof(char *));
	if (!words)
		return (NULL);
	words = fill_words(s, c, words, num_words);
	return (words);
}

/*int	main(void)
{
	char	*cadena = "      split       this for   me  !       ";
	char	de = ' ';
	char	**result;
	int		i;

	i = 0;
	result = ft_split(cadena, de);
	if (result)
	{
		while (result && result[i])
		{
			printf("palabra %d = %s\n", i + 1, result[i]);
			i++;
		}
		free_array(result, count_words(cadena, de));
	}
	return (0);
}*/
