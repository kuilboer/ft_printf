/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 17:53:26 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/24 11:24:23 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
* ft_strchr() looks for the first occurance of byte character 'c' in string 's'
* and returns a pointer to that character's position in string 's'.
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
