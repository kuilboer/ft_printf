/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/25 12:45:19 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/04 15:10:06 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlen() function calculates the length of the string pointed to by s,
excluding the terminating null byte ('\0').
Return:
	- number of bytes in the string pointed to by s;
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return ((size_t)i);
}
