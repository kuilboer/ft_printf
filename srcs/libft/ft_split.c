/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 15:07:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 11:58:35 by okuilboe      ########   odam.nl         */
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

/*
* alloc_word, creates a new string and reserves a memory area for it of
* 'len + 1' bytes and copies the first 'len' bytes from string 's' to it before
* terminating the new string with a '\0' character.
* It returns a pointer to the copied string 'word'.
*/
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

/*
* fill_split() loops over the input string to find the words to copy.
* it loops over the characters until it finds the first character of
* a word. it then measures thte length of the word by counting the 
* characters upto the next delimiter or end of string.
* a pointer to the starting character and its length is than passed to the
* function alloc_word tp reserve memory and copy the string.
* After the last word has been processed, fill_split terminates the last
* Possition of the array with a NULL pointer for safe processing later on.
*/
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

/*
* Allocates memory (using malloc(3)) and returns an array of strings obtained
* by splitting ’s’ using the character ’c’ as a delimiter. The last array el-
* lement is NULL pointer terminated.
*
* Parameters: 
*	- s: Pointer to string to be split;
* 	- c: byte character that is used as the delimiter for splitting;
*
* Returns:
*	- A pointer to the array of new strings resulting from the split.
*	- NULL if the allocation fails.
*/
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
