/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/17 22:23:41 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/17 23:01:21 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memchr() function scans the initial 'n' bytes of the memory area pointed to
by 's' for the first instance of 'c'.  Both c and the bytes of the memory are
pointed to by 's' are interpreted as unsigned char.

Parameters:
	- s Pointer to first byte in search memory area;
	- c unsigned char to search for;
	- n unsigned int indicating the number of bytes to search.

Return: 
	- functions return a pointer to the matching byte OR,
	- NULL if the character does not occur in the given memory area.

*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
