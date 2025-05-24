/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 13:50:12 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 10:45:49 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* The  memmove() function copies n bytes from memory area src to memory area 
* dest.
* The memory areas may overlap: copying takes place as though the bytes in src 
* are first copied into a temporary array that does not overlap src or dest,
* and the bytes are then copied from the temporary array to dest.
*
* Parameters:
*	- src : pointer to memory area that holds the source datat;
*	- dest: pointer to memory area to store the copied data to;
*	- n   : Interger the specified the maximumm number of bytes to be copied.
*
*	Retrurns:
*	- a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_buf;
	unsigned char	*s_buf;

	d_buf = (unsigned char *)dest;
	s_buf = (unsigned char *)src;
	if (!dest && !src && n > 0)
		return (NULL);
	else if (d_buf < s_buf)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i-- > 0)
			d_buf[i] = s_buf[i];
	}
	return ((void *)dest);
}
