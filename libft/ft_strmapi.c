/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/17 15:50:38 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/17 17:20:06 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function 'f' to each character of the string 's', passing its index
as the first argument and the character itself as the second.
A new string is created (using malloc(3)) to store the results from the
successive applications of f.
Parameters:
	- s: The string to iterate over.
	- f: The function to apply to each character.
Return values:
	- The string created from the successive applications of ’f’.
	- NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(s);
	new_str = malloc(str_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
