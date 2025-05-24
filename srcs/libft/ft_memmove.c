/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 13:50:12 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/16 21:36:07 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
