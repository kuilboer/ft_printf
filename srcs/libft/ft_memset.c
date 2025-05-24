/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/25 13:03:21 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 10:51:34 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
* The memset() function fills the first n bytes of the memory area pointed to
* by s with the constant byte c.
*
* Parameters: 
*	- s: pointer to memory area that needs to be initialized;
*	- c: byte code to write to the memory area s;
*	- n: maximum number of bytes to be written.
*
* Returns:
*	- pointer to memory area s;
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}
