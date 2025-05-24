/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 19:28:39 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/16 20:49:04 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_needle(const char *big, const char *little, \
	size_t big_i, size_t len)
{
	int	lit_i;

	lit_i = 0;
	while (little[lit_i])
	{
		if (big_i >= len || !big[big_i])
			return (0);
		if (big[big_i] != little[lit_i])
			return (0);
		lit_i++;
		big_i++;
	}
	return (1);
}

/*
The strnstr() function locates the first occurrence of the null-terminated 
string 'little' in the string 'big', where not more than len characters are 
searched. Characters that appear after a ‘\0’ character are not searched.

If little is an empty string, big is returned; if little occurs nowhere in big,
NULL is returned;

Otherwise a pointer to the first character of the first occurrence of little is
returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_len;

	if (*little == '\0')
		return ((char *)big);
	big_len = ft_strlen(big);
	if (len > big_len)
		len = big_len;
	i = 0;
	while (i < len)
	{
		if (big[i] == little[0])
		{
			if (is_needle(big, little, i, len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
