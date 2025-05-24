/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 20:07:08 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 11:38:39 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Allocates memory (using malloc(3)) and returns a new string, which is the re-
* sult of concatenating ’s1’ and ’s2’.
*
* Parameters:
*	- s1: string value;
*	- s2: string value to concatenate from to the end of s1;
* Returns:
* 	- new_str: The new string created in the concatenation process;
*	- NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	str1_len;
	size_t	str2_len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	new_str = malloc((str1_len + str2_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < (str1_len + str2_len))
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}
