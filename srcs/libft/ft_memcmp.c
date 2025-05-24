/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 15:56:04 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 12:01:15 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The memcmp() function compares the first n bytes (each interpreted as un-
* signed char) of the memory areas s1 and s2.
*
* Parameters:
*	- *s1 pointer to memory buffer;
*	- *s2 pointer to memory buffer;
*	- n number of bytes to read and compare.abort
*
* Returns:
*	- function returns an integer less than, equal to, or greater than zero if
* 	  the first n bytes of s1 is found, respectively, to be less than, to match,
*	  or be greater than the first n bytes of s2.
*	- For a nonzero return value, the sign is determined by the sign of the dif-
*	  ference between the first pair of bytes (interpreted as unsigned char) 
*	  that differ in s1 and s2.
*	- If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
