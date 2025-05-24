/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 17:53:26 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 11:41:41 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
Let the while loop run forever and implement clear break cases.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
