/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/01 14:28:57 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/19 15:24:51 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  strlcpy()  and  strlcat() functions copy and concatenate strings respectiv-
ely.  They are designed to be safer, more consistent, and less error prone re-
placements for strncpy(3) and strncat(3).

Unlike those functions, strlcpy() and strlcat() take the full size of the buffer
(not just the length) and guarantee to NUL-terminate the result (as long as 
size is larger than 0 or, in the case of strlcat(), as long as there is at
least one byte free in dst).

Note that a byte for the NUL should be included in size. 
Also note  that  strlcpy() and strlcat() only operate on true “C” strings.  This
means that for strlcpy() src must be NUL-terminated and for strlcat() both src
and dst must be NUL-terminated.

Parameters: 
	- 'dest': pointer to reserved buffer to cpy to.
	- 'src'	: pointer to string to copy from.
	- 'size': Maximum string length to cpy. 
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return ((size_t)i);
}
