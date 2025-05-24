/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/01 20:35:41 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 12:01:31 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* The strlcat() function appends the NUL-terminated string src to the end of
* dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the
* result.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return ((size_t)(size + src_len));
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	if (dst)
		dst[i + dst_len] = '\0';
	return ((size_t)(dst_len + src_len));
}
