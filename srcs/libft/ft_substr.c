/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 18:00:46 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/18 12:36:39 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory (using malloc(3)) and returns a substring from the string ’s’.
The substring starts at index ’start’ and has a maximum length of ’len’.
Parameters: 
	- 's':      Source string;
	- 'start':  The starting index of the sub string to copy;
	- 'len':    Maximum length of substring to cpy;
Returns: 
	- Substring;
	- NULL if memory allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_len;
	size_t	sub_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	sub_len = str_len - start;
	if (sub_len > len)
		sub_len = len;
	sub_str = malloc((sub_len + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
