/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 14:48:22 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 12:13:28 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
run forever to also catch '/0' edge case. (while (1) 
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (1)
	{
		if (*s == (char)c)
		{
			ptr = (char *)s;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (ptr);
}
