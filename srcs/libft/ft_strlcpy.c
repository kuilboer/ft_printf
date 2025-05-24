/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/01 14:28:57 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 11:46:20 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*strlcpy() copies strings. It takes the full size of the buffer
*(not just the length) and guarantees to NUL-terminate the result (as long as 
*size is larger than 0.
*
*Note that a byte for the NUL should be included in size. 
*src must be NUL-terminated.
*
* Parameters:
*	- 'dest': pointer to reserved buffer to cpy to.
*	- 'src'	: pointer to string to copy from.
*	- 'size': Maximum string length to cpy.
*
* Returns:
*	- The total length of the string it tried to create, e.g. the length of src.
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
