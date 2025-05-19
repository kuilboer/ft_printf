/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 14:51:34 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/18 22:52:07 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strdup() function returns a pointer to a new string which is a duplicate of
the string s.  Memory for the new string is obtained with malloc(3), and can be
freed with free(3).

Parameters:
	- 's': source string to duplicate;

Returns:
	- On success, the strdup() function returns a pointer to the duplicated
	  string.  It returns NULL if insufficient memory was available, with errno
	  set to indicate the error.
*/
char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		s_len;

	s_len = ft_strlen(s);
	new_str = malloc((s_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, (s_len + 1));
	return (new_str);
}
