/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:07:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/16 13:48:04 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int		count;
	int		in_word;
	int		i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	free_words(char **arr, int filled)
{
	int		i;

	i = 0;
	while (i < filled)
		free(arr[i++]);
	free(arr);
}

static char	*alloc_word(const char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_split(char **res, const char *s, char c)
{
	int		i;
	int		len;
	int		word_i;

	i = 0;
	word_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			res[word_i] = alloc_word(&s[i], len);
			if (!res[word_i])
				return (free_words(res, word_i), 0);
			word_i++;
			i += len;
		}
	}
	res[word_i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (!fill_split(result, s, c))
		return (NULL);
	return (result);
}
