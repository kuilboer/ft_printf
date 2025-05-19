/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 16:28:11 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 12:09:47 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*	The strncmp() function compares the first (at most) n bytes of s1 and s2
	The locale is not taken into account. The comparison is done using unsigned
	characters.
		strncmp() returns an integer indicating the result of the comparison, 
		as follows:
		• 0, if the s1 and s2 are equal;
		• a negative value if s1 is less than s2;
		• a positive value if s1 is greater than s2.
		The strncmp() compares only the first (at most) n bytes of s1 and s2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
